/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** event for buttons
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/components/component_ids.h"

void on_hover_sprite_btn(win_t UNUSED *w, component_t *c, sfEvent UNUSED *e)
{
    c->self.sprite._rect.left = c->self.sprite._rect.width;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
}

void on_leave_sprite_btn(win_t UNUSED *w, component_t *c, sfEvent UNUSED *e)
{
    c->self.sprite._rect.left = 0;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
}
