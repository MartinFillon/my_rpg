/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init portal
*/

#include "my_json.h"
#include "my_map.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"

void init_main_menu_portal(json_elem_t *j, component_t *c)
{
    init_anim_sprite(j, c);

    float c_x = c->bounds.width / 2.0;
    float c_y = c->bounds.height / 2.0;

    sfSprite_setOrigin(c->self.anim_sprite._spr, (sfVector2f){c_x, c_y});
    sfSprite_setPosition(
        c->self.anim_sprite._spr, (sfVector2f){c->bounds.left, c->bounds.top}
    );
}
