/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** on_event_in_game_menu
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

void on_hover_in_game_btn(win_t UNUSED *w, component_t *c, sfEvent UNUSED *e)
{
    if (c->self.sprite._rect.left == c->self.sprite._rect.width * 2)
        return;
    c->self.sprite._rect.left = c->self.sprite._rect.width;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
}

void on_leave_in_game_btn(win_t UNUSED *w, component_t *c, sfEvent UNUSED *e)
{
    if (c->self.sprite._rect.left == c->self.sprite._rect.width * 2)
        return;
    c->self.sprite._rect.left = 0;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
}

void on_hover_in_game_item(win_t UNUSED *w, component_t *c, sfEvent UNUSED *e)
{
    if (c->self.sprite._rect.left == c->self.sprite._rect.width * 3 ||
        c->self.sprite._rect.left == 0)
        return;
    c->self.sprite._rect.left = c->self.sprite._rect.width * 2;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
}

void on_leave_in_game_item(win_t UNUSED *w, component_t *c, sfEvent UNUSED *e)
{
    if (c->self.sprite._rect.left == c->self.sprite._rect.width * 3 ||
        c->self.sprite._rect.left == 0)
        return;
    c->self.sprite._rect.left = c->self.sprite._rect.width;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
}
