/*
** EPITECH PROJECT, 2023
** on_click_on_button_quest.c
** File description:
** manage the click btn on quest btn
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

void on_click_on_quest_btn(win_t *w, component_t UNUSED *c, sfEvent UNUSED *e)
{
    if (c->id == GAME_MENU_QUEST_BTN) {
        switch_scene(w, IN_GAME_MENU_QUEST);
        reset_game_menu_btn(w);
        c->self.sprite._rect.left = c->self.sprite._rect.width * 2;
        sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
    }
}
