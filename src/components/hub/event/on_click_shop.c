/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** on_click_shop
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static const int offset = SHOP_BETH - GAME_MENU_INVENTORY_BOX_1;

static void reset_shop_click(win_t *w)
{
    for (int i = SHOP_BOOST_ATCK1; i <= SHOP_BACK_BTN; i++) {
        w->c[i].self.sprite._rect.left = 0;
        sfSprite_setTextureRect(
            w->c[i].self.sprite._spr, w->c[i].self.sprite._rect
        );
    }
}

static void is_avaible_for_purchase(win_t *w, int i)
{
    if (w->c[i].self.sprite._rect.left == w->c[i].self.sprite._rect.width * 2) {
        if (w->c[MAIN_CHARACTER].self.character.coins < 1000)
            return;
        if (w->c[MAIN_CHARACTER].self.character.coins >= 1000 &&
        (i == SHOP_BOOST_ATCK1 ||
        i == SHOP_BOOST_HP1 || i == SHOP_BOOST_SHIELD1)) {
            w->c[MAIN_CHARACTER].self.character.coins -= 1000;
        }
        if (w->c[MAIN_CHARACTER].self.character.coins >= 2000 &&
        (i == SHOP_BOOST_ATCK2 ||
        i == SHOP_BOOST_HP2 || i == SHOP_BOOST_SHIELD2)) {
            w->c[MAIN_CHARACTER].self.character.coins -= 2000;
        }
        w->c[i - offset].self.sprite._rect.left =
        w->c[i - offset].self.sprite._rect.width;
        sfSprite_setTextureRect(w->c[i - offset].self.sprite._spr,
        w->c[i - offset].self.sprite._rect);
    }
}

void on_click_shop(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    if (c->id >= SHOP_BOOST_ATCK1 && c->id <= SHOP_BOOST_SHIELD2) {
        reset_shop_click(w);
        c->self.sprite._rect.left = c->self.sprite._rect.width * 2;
        sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
    }
    if (c->id == SHOP_BACK_BTN) {
        reset_shop_click(w);
        switch_scene(w, HUB);
    }
    if (c->id == SHOP_BUY_BTN) {
        for (int i = SHOP_BOOST_ATCK1; i <= SHOP_BOOST_SHIELD2; i++) {
            is_avaible_for_purchase(w, i);
        }
        reset_shop_click(w);
    }
}
