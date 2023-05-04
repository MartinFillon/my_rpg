/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy minimap
*/

#include "myrpg/components/defs.h"

void destroy_minimap(component_t *c)
{
    mini_map_t *self = &c->self.mini_map;

    sfView_destroy(self->_view);
    sfSprite_destroy(self->_spr);
    sfTexture_destroy(self->_tex);
    sfRectangleShape_destroy(self->_bg);
}
