/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** init_projectiles
*/

#include "my_json.h"
#include "my_stdio.h"
#include "my_vec.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/window.h"

void init_projectiles(json_elem_t *j, component_t *c)
{
    init_sprite(j, c);
    c->self.projectiles._clock = sfClock_create();
    c->self.projectiles.max_travel_distance =
        json_get_number(j, 1, "travel_distance");
    c->self.projectiles.data = vec_create(10000, sizeof(projectile_data_t));
}
