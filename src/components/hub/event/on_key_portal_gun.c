/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** on_click_portal_gun
*/

#include "my_stdio.h"

#include "myrpg/components/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

void on_key_portal_gun(win_t *w, component_t *c, sfEvent *e)
{
    if (e->key.code == w->settings.interact &&
        sfFloatRect_intersects(
            &w->c[MAIN_CHARACTER].bounds, &c->bounds, NULL
        )) {
        c->show = sfFalse;
        w->c[MAIN_CHARACTER].self.character.quest += 1;
        w->c[GAME_MENU_INVENTORY_BOX_1].self.sprite._rect.left =
            w->c[GAME_MENU_INVENTORY_BOX_1].self.sprite._rect.width;
        sfSprite_setTextureRect(
            w->c[GAME_MENU_INVENTORY_BOX_1].self.sprite._spr,
            w->c[GAME_MENU_INVENTORY_BOX_1].self.sprite._rect
        );
    }
}
