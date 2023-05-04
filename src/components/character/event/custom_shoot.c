/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** custon_shoot
*/

#include "my_stdio.h"
#include "my_utils.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/events.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"
#include "myrpg/systems/system_ids.h"

static int EXCLUDED[] = {
    GAME_MENU_ICON,
    GAME_SETTINGS_ICON,
    -1,
};

static sfBool verify_excluded(win_t *w, sfVector2i mouse_pos)
{
    for (size_t i = 0; EXCLUDED[i] != -1; i++) {
        if (w->c[EXCLUDED[i]].show &&
            sfFloatRect_contains(
                &w->c[EXCLUDED[i]].bounds, mouse_pos.x, mouse_pos.y
            ))
            return sfFalse;
    }
    return sfTrue;
}

void on_custom_shoot(win_t *w, component_t *c, sfEvent *e)
{
    sfVector2f pos;
    sfVector2i mouse_pos;

    if (e->type == sfEvtMouseButtonPressed &&
        e->mouseButton.button == sfMouseLeft) {
        pos = (sfVector2f
        ){c->bounds.left + c->bounds.width / 2,
        c->bounds.top + c->bounds.height / 2};
        mouse_pos = get_mouse_pos(w, e);
        if (!verify_excluded(w, mouse_pos))
            return;
        register_projectile(
            w, pos, mouse_pos, c->self.character.stats.atk_speed
        );
        play_sound(&w->s[SOUND], STR("shoot"));
    }
}
