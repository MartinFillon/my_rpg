/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** defs
*/

#ifndef COMPONENTS_DEFS_H_
    #define COMPONENTS_DEFS_H_

    #include "myrpg/components/types.h"
    #include "myrpg/window.h"


// UTILS
void set_movement_animation(component_t *, int direction);
float component_distance_pow2(component_t *, component_t *);

void init_component_bounds(component_t *, json_elem_t *);
void init_sprite_rect(json_elem_t *, component_t *);

void init_sprite(json_elem_t *, component_t *);
void init_game_map(json_elem_t *, component_t *);
void init_anim_sprite(json_elem_t *, component_t *);
void init_text(json_elem_t *, component_t *);
void init_npc(json_elem_t *, component_t *);
void init_stats(json_elem_t *, struct stats_s *);

void draw_sprite(win_t *, component_t *);
void draw_quest_bubble(win_t *, component_t *);
void draw_enemy(win_t *, component_t *);
void draw_text(win_t *, component_t *);
void draw_quest_text(win_t *, component_t *);

void on_hover_sprite_btn(win_t *, component_t *, sfEvent *);
void on_leave_sprite_btn(win_t *, component_t *, sfEvent *);

void destroy_npc(component_t *);
void destroy_game_map(component_t *);
void destroy_anim_sprite(component_t *);
void destroy_sprite(component_t *);
void destroy_text(component_t *);
// !UTILS


// CHARACTER
void draw_character_stats(win_t *, component_t *);
void init_character(json_elem_t *, component_t *);
void change_skin(win_t *);
void character_interact(win_t *, component_t *, sfEvent *);
void on_custom_shoot(win_t *, component_t *, sfEvent *);
void on_custom_particle(win_t *, component_t *, sfEvent *);
// !CHARACTER


// ENEMY
void init_enemies(json_elem_t *, component_t *);
void draw_enemy(win_t *, component_t *);
void destroy_enemies(component_t *);
void set_bestiary(win_t *, size_t i);
sfBool handle_enemy_damage(win_t *, double damage);
sfBool move_enemy(win_t *, enemy_t *, size_t);
void move_enemies_with_map(win_t *, sfVector2f);
void spawn_enemies(win_t *, enemy_t *);
// !ENEMY


// SHOOT
void register_projectile(win_t *, sfVector2f, sfVector2i, float atk_speed);
void init_projectiles(json_elem_t *, component_t *);
void draw_projectiles(win_t *, component_t *);
void destroy_projectile(component_t *);
void move_projectiles(win_t *, sfVector2f);
// !SHOOT


// DIALOG
void init_dialog(json_elem_t *, component_t *);
void draw_dialog(win_t *, component_t *);
void destroy_dialog(component_t *);
void key_text_event(win_t *, component_t *, sfEvent *);
// !DIALOG


// MAIN_MENU
void init_main_menu_portal(json_elem_t *, component_t *);

void on_custom_main_menu_portal(win_t *, component_t *, sfEvent *);
void on_click_main_menu_button(win_t *, component_t *, sfEvent *);

void draw_main_menu_portal(win_t *, component_t *);
void draw_main_menu_button(win_t *, component_t *);
void on_click_help(win_t *, component_t *, sfEvent *);
// !MAIN_MENU


// SETTINGS
void on_click_select_skin_btn(win_t *, component_t *, sfEvent *);

void on_click_settings_button(win_t *, component_t *, sfEvent *);
void on_release_settings_button(win_t *, component_t *, sfEvent *);

void on_click_settings_audio_button(win_t *, component_t *, sfEvent *);

void on_click_settings_video_button(win_t *, component_t *, sfEvent *);
void on_click_key_maps(win_t *, component_t *, sfEvent *);
void on_key_keymaps(win_t *, component_t *, sfEvent *);
// !SETTINGS


// SAVE_MENU
void on_click_save_menu_btn(win_t *, component_t *, sfEvent *);
// !SAVE_MENU


// SELECT_SKIN
void on_click_select_skin_btn(win_t *, component_t *, sfEvent *);
// !SELECT_SKIN


// HUB
void draw_portal_gun(win_t *, component_t *);
void on_key_escape_game(win_t *, component_t *, sfEvent *);
void draw_portal(win_t *, component_t *);
void on_custom_hub_portal(win_t *, component_t *, sfEvent *);
void draw_hub_map(win_t *, component_t *);
void set_movement_particle(win_t *, sfVector2f);
void on_key_death_animation(win_t *, component_t *, sfEvent *);
// !HUB


// SHOP
void on_click_shop(win_t *, component_t *, sfEvent *);
// !SHOP


// IN_GAME_MENU
void on_hover_in_game_btn(win_t *, component_t *, sfEvent *);
void on_click_in_game_btn(win_t *, component_t *, sfEvent *);
void on_click_on_quest_btn(win_t *, component_t *, sfEvent *);
void on_leave_in_game_btn(win_t *, component_t *, sfEvent *);
void on_click_in_game_skin_btn(win_t *, component_t *, sfEvent *);
void on_leave_in_game_item(win_t *, component_t *, sfEvent *);
void on_hover_in_game_item(win_t *, component_t *, sfEvent *);
void reset_game_menu_box(win_t *w);
void reset_game_menu_btn(win_t *w);
// !IN_GAME_MENU

// QUEST
void destroy_quests(component_t *);
void draw_quests(win_t *, component_t *);
void init_quests(json_elem_t *, component_t *);
void on_key_portal_gun(win_t *, component_t *, sfEvent *);
void manage_quest_morty_kill(win_t *, component_t *);
void manage_quest_portal_gun(win_t *, component_t *);
// !QUEST

// MINI_MAP
void destroy_minimap(component_t *);
void draw_minimap(win_t *, component_t *);
void init_minimap(json_elem_t *, component_t *);
// !MINI_MAP


// PROCEDURAL_MAP
void init_procedural_map(json_elem_t *, component_t *);
void draw_procedural_map(win_t *, component_t *);
void destroy_procedural_map(component_t *);
void destroy_chunk(chunk_t *);
void clear_procedural_map(win_t *);

void generate_first_chunk(component_t *, int tile_idx);
void generate_new_chunk(procedural_map_t *, chunk_t *, sfIntRect inter);
float perlin2d(sfVector2i pos, float freq, unsigned int depth, int seed);
chunk_t generate_procedural_chunk(
    int seed, sfVector2i origin, char const *tile_path
);
// !PROCEDURAL_MAP


// SELECT_MAP
void on_click_select_map(win_t *, component_t *, sfEvent *);
// !SELECT_MAP


#endif /* !COMPONENTS_DEFS_H_ */
