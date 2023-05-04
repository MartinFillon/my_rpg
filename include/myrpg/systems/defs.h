/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** defs
*/

#ifndef SYSTEMS_DEFS_H_
    #define SYSTEMS_DEFS_H_

    #include "myrpg/systems/types.h"
    #include "my_json.h"


// SOUND
void init_sound(json_elem_t *, system_t *);
void destroy_sound(system_t *);
// !SOUND


// MUSIC
void init_music(json_elem_t *, system_t *);
void destroy_music(system_t *);
// !MUSIC


// SAVE
void update_save_menu_loads(win_t *);
void load_save(win_t *, size_t slot_idx);
void save_game_state(win_t *, system_t *);
void init_save(json_elem_t *, system_t *);
void destroy_save(system_t *);
str_t *compress_string(str_t *);
str_t *decompress_string(str_t *);
// !SAVE


#endif /* !SYSTEMS_DEFS_H_ */
