/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** on_click_in_game_menu
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/systems/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static const int LOCKED[] = {
    MAIN_CHARACTER, HUB_VIGNETTE, GAME_MENU_ICON, GAME_SETTINGS_ICON, -1,
};

void on_click_in_game_skin_btn(
    win_t UNUSED *w, component_t *c, sfEvent UNUSED *e
)
{
    if (c->id == IN_GAME_SKIN_SELECT_BTN) {
        change_skin(w);
        switch_scene(w, GAME_MENU);
    }
    if (c->id == IN_GAME_SKIN_BACK_BTN) {
        switch_scene(w, GAME_MENU);
    }
}

static void on_click_features_in_game_btn(
    win_t UNUSED *w, component_t *c, sfEvent UNUSED *e
)
{
    int skin_id;
    component_t *comp = &w->c[GAME_MENU_SKIN];

    if (c->id == GAME_MENU_SKIN_BTN) {
        switch_scene(w, IN_GAME_MENU_SKIN);
        reset_game_menu_btn(w);
    }
    if (c->id == GAME_MENU_INVENTORY_BTN) {
        switch_scene(w, GAME_MENU_INVENTORY);
        skin_id = pipe_read(STR("skin_id"));
        pipe_write(STR("skin_id"), skin_id);
        comp->self.sprite._rect.left = comp->self.sprite._rect.width * skin_id;
        sfSprite_setTextureRect(
            comp->self.sprite._spr, comp->self.sprite._rect
        );
    }
    if (c->id == GAME_MENU_BESTIARY_BTN)
        switch_scene(w, IN_GAME_MENU_BESTIARY);
}

void on_use_item(win_t *w, component_t *c)
{
    component_t *comp = &w->c[MAIN_CHARACTER];
    if (c->id == GAME_MENU_INVENTORY_BOX_1) {
        switch_scene(w, HUB);
        move_scene_components(w, LOCKED, (sfVector2f){0, -200});
        return;
    }
    if (c->id == GAME_MENU_INVENTORY_BOX_2)
        comp->self.character.stats.atk += 10;
    if (c->id == GAME_MENU_INVENTORY_BOX_3)
        comp->self.character.stats.atk += 20;
    if (c->id == GAME_MENU_INVENTORY_BOX_4)
        comp->self.character.stats.hp += 10;
    if (c->id == GAME_MENU_INVENTORY_BOX_5)
        comp->self.character.stats.hp += 20;
    if (c->id == GAME_MENU_INVENTORY_BOX_6)
        comp->self.character.stats.def += 10;
    if (c->id == GAME_MENU_INVENTORY_BOX_7)
        comp->self.character.stats.def += 20;
    c->self.sprite._rect.left = 0;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
}

static void on_click_custom(win_t *w, component_t *c)
{
    if (c->id == GAME_MENU_QUIT_BTN)
        switch_scene(w, MAIN_MENU);
    if (c->id == GAME_MENU_ICON) {
        pipe_write(STR("previous_scene"), w->current_scene);
        switch_scene(w, GAME_MENU);
    }
    if (c->id == GAME_MENU_BACK_BTN) {
        reset_game_menu_btn(w);
        switch_scene(w, pipe_pop(STR("previous_scene")));
    }
    if (c->id == GAME_SETTINGS_ICON) {
        pipe_write(STR("previous_scene"), w->current_scene);
        switch_scene(w, SETTINGS);
    }
}

void on_click_in_game_btn(win_t UNUSED *w, component_t *c, sfEvent UNUSED *e)
{
    if (c->id >= GAME_MENU_INVENTORY_BTN && c->id <= GAME_MENU_SKIN_BTN) {
        reset_game_menu_btn(w);
        c->self.sprite._rect.left = c->self.sprite._rect.width * 2;
        sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
        on_click_features_in_game_btn(w, c, e);
    }
    if (c->id >= GAME_MENU_INVENTORY_BOX_1 &&
        c->id <= GAME_MENU_INVENTORY_BOX_7) {
        if (c->self.sprite._rect.left != 0) {
            reset_game_menu_box(w);
            c->self.sprite._rect.left = c->self.sprite._rect.width * 3;
            sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
            on_use_item(w, c);
        }
    }
    on_click_custom(w, c);
}
