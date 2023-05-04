/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy game map
*/

#include "myrpg/components/defs.h"

void destroy_game_map(component_t *c)
{
    sfSprite_destroy(c->self.sprite._spr);
    sfTexture_destroy(c->self.sprite._tex);
    sfImage_destroy(c->self.map._alpha);
    sfClock_destroy(c->self.map._clock);
}
