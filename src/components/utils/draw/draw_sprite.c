/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw sprite util
*/

#include "myrpg/pipe.h"
#include "myrpg/components/defs.h"
#include "myrpg/components/component_ids.h"

void draw_sprite(win_t *w, component_t *c)
{
    sfRenderWindow_drawSprite(w->self, c->self.sprite._spr, NULL);
}

void draw_map(win_t *w, component_t *c)
{
    sfRenderWindow_drawSprite(w->self, c->self.map._spr, NULL);
}

void draw_anim_sprite(win_t *w, component_t *c)
{
    sfRenderWindow_drawSprite(w->self, c->self.anim_sprite._spr, NULL);
}
