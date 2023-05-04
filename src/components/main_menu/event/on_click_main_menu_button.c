/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** on_click_main_menu_button
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

void on_click_main_menu_button(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    if (w->c[MAIN_MENU_PORTAL].self.anim_sprite._anim_state == ANIM_FORWARD)
        return;
    if (c->id == MAIN_MENU_PLAY_BTN)
        pipe_write(STR("next_scene"), SAVE_MENU);
    if (c->id == MAIN_MENU_HELP_BTN)
        pipe_write(STR("next_scene"), HELP);
    if (c->id == MAIN_MENU_SETTINGS_BTN) {
        pipe_write(STR("previous_scene"), MAIN_MENU);
        pipe_write(STR("next_scene"), SETTINGS);
    }
    if (c->id == MAIN_MENU_QUIT_BTN)
        sfRenderWindow_close(w->self);

    w->c[MAIN_MENU_PORTAL].self.anim_sprite._anim_state = ANIM_FORWARD;
}

void on_click_help(win_t *w, component_t UNUSED *c, sfEvent UNUSED *e)
{
    switch_scene(w, MAIN_MENU);
}
