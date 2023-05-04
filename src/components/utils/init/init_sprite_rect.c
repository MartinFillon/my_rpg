/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init rect of sprite
*/

#include "my_json.h"

#include "myrpg/components/defs.h"

void init_sprite_rect(json_elem_t *j, component_t *c)
{
    c->self.sprite._rect = (sfIntRect){
        json_get_number(j, 2, "rect", "left"),
        json_get_number(j, 2, "rect", "top"),
        json_get_number(j, 2, "rect", "width"),
        json_get_number(j, 2, "rect", "height"),
    };
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
}
