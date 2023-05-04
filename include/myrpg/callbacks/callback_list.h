/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** callbacks_lists
*/

#ifndef CALLBACK_LIST_H_
    #define CALLBACK_LIST_H_

    #include "myrpg/components/defs.h"
    #include "myrpg/events.h"
    #include "myrpg/callbacks/defs.h"

    #define NB_CALLBACKS (sizeof(CALLBACKS) / sizeof(callback_list_t))


typedef struct {
    char *name;
    void (*callback)(win_t *, struct component_s *, sfEvent *);
} callback_list_t;

static const callback_list_t CALLBACKS[] = {
    {"stop_propagation", &stop_propagation},
    {"on_hover_sprite_btn", &on_hover_sprite_btn},
    {"on_leave_sprite_btn", &on_leave_sprite_btn},

    {"on_custom_main_menu_portal", &on_custom_main_menu_portal},
    {"on_click_main_menu_button", &on_click_main_menu_button},
    {"on_click_help", &on_click_help},

    {"on_click_save_menu_btn", &on_click_save_menu_btn},

    {"on_click_select_skin_btn", &on_click_select_skin_btn},
    {"on_click_in_game_skin_btn", &on_click_in_game_skin_btn},

    {"on_hover_in_game_btn", &on_hover_in_game_btn},
    {"on_click_in_game_btn", &on_click_in_game_btn},
    {"on_click_on_quest_btn", &on_click_on_quest_btn},
    {"on_leave_in_game_btn", &on_leave_in_game_btn},
    {"on_hover_in_game_item", &on_hover_in_game_item},
    {"on_leave_in_game_item", &on_leave_in_game_item},
    {"on_key_death_animation", &on_key_death_animation},

    {"on_click_select_map", &on_click_select_map},

    {"on_custom_hub_portal", &on_custom_hub_portal},
    {"on_key_portal_gun", &on_key_portal_gun},

    {"on_click_shop", &on_click_shop},

    {"on_key_escape_game", &on_key_escape_game},

    {"on_click_settings_button", &on_click_settings_button},
    {"on_click_settings_video_button", &on_click_settings_video_button},
    {"on_click_settings_audio_button", &on_click_settings_audio_button},
    {"on_click_key_maps", &on_click_key_maps},
    {"on_key_keymaps", &on_key_keymaps},

    {"character_interact", &character_interact},
    {"on_custom_shoot", &on_custom_shoot},
    {"on_custom_particle", &on_custom_particle}
};


#endif /* !CALLBACK_LIST_H_ */
