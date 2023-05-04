/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** register_projectile
*/

#include <math.h>

#include "my_stdio.h"
#include "my_utils.h"
#include "my_vec.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/systems/system_ids.h"

// clang-format off
void register_projectile(
    win_t *w, sfVector2f pos, sfVector2i mouse_pos, float atk_sp
)
{
    component_t *c = &w->c[PROJECTILE];
    sfVector2f sens = {
        (mouse_pos.x - pos.x > 0.0) ? 1.0 : -1.0,
        (mouse_pos.y - pos.y > 0.0) ? 1.0 : -1.0};
    float off_x = FABS(mouse_pos.x - pos.x);
    float off_y = FABS(mouse_pos.y - pos.y);
    if (off_x > w->size.x / 2.0) {
        sens.x *= -1.0;
        off_x = w->size.x - off_x;
    }
    if (off_y > w->size.y / 2.0) {
        sens.y *= -1.0;
        off_y = w->size.y - off_y;
    }
    float d_ = sqrtf((off_x * off_x) + (off_y * off_y));
    projectile_data_t data = {
        pos, {atk_sp * (sens.x * off_x / d_), atk_sp * (sens.y * off_y / d_)},
        pos, sfTrue, TO_DEG(atan2f(sens.y * off_y, sens.x * off_x))
    };
    vec_pushback(&c->self.projectiles.data, &data);
}
// clang-format on
