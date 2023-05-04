/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** on_hover_play_bis
*/

#include "myrpg/components/types.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/systems/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

void on_click_save_menu_btn(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    switch (c->id) {
        case SAVE_MENU_BACK_BTN: switch_scene(w, MAIN_MENU); break;
        case SAVE_MENU_SLOT_1:
        case SAVE_MENU_SLOT_2:
        case SAVE_MENU_SLOT_3:
            load_save(w, c->id - SAVE_MENU_SLOT_1);
            switch_scene(w, SELECT_SKIN);
            break;
    }
    w->stop_propagation = sfTrue;
}
