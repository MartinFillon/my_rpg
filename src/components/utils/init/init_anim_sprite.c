/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init sprite util
*/

#include "myrpg/components/defs.h"

void init_anim_sprite(json_elem_t *j, component_t *c)
{
    c->self.anim_sprite._spr = sfSprite_create();
    c->self.anim_sprite._clock = sfClock_create();
    str_t *str = json_get_string(j, 1, "texture");

    if (!str || !c->self.anim_sprite._spr || !c->self.anim_sprite._clock)
        return;

    c->self.anim_sprite._tex = sfTexture_createFromFile(str_tocstr(str), NULL);
    sfSprite_setTexture(
        c->self.anim_sprite._spr, c->self.anim_sprite._tex, sfFalse
    );
    init_sprite_rect(j, c);
    init_component_bounds(c, j);
    sfSprite_setPosition(
        c->self.anim_sprite._spr, (sfVector2f){c->bounds.left, c->bounds.top}
    );
}
