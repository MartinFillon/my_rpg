/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy sprite
*/

#include "myrpg/components/defs.h"

void destroy_anim_sprite(component_t *c)
{
    if (c->self.sprite._spr != NULL)
        sfSprite_destroy(c->self.sprite._spr);
    if (c->self.sprite._tex != NULL)
        sfTexture_destroy(c->self.sprite._tex);
    if (c->self.anim_sprite._clock != NULL)
        sfClock_destroy(c->self.anim_sprite._clock);
}
