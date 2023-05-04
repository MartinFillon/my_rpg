/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** reset_in_game_menu
*/

#include "myrpg/components/defs.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static const int LOCKED[] = {
    MAIN_CHARACTER, GAME_MENU_ICON, HUB_VIGNETTE, GAME_SETTINGS_ICON, -1,
};

void reset_game_menu_box(win_t *w)
{
    for (int i = GAME_MENU_INVENTORY_BOX_1; i <= GAME_MENU_INVENTORY_BOX_7;
         i++) {
        if (w->c[i].self.sprite._rect.left == 0)
            continue;
        w->c[i].self.sprite._rect.left = w->c[i].self.sprite._rect.width;
        sfSprite_setTextureRect(
            w->c[i].self.sprite._spr, w->c[i].self.sprite._rect
        );
    }
}

void reset_game_menu_btn(win_t *w)
{
    for (int i = GAME_MENU_INVENTORY_BTN; i <= GAME_MENU_SKIN_BTN; i++) {
        w->c[i].self.sprite._rect.left = 0;

        sfSprite_setTextureRect(
            w->c[i].self.sprite._spr, w->c[i].self.sprite._rect
        );
    }
}

void on_key_death_animation(win_t *w, component_t UNUSED *c, sfEvent UNUSED *e)
{
    switch_scene(w, HUB);

    move_scene_components(w, LOCKED, (sfVector2f){0, -200});
}
