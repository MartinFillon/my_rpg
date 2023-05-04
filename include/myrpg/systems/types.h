/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** types
*/

#ifndef SYSTEM_TYPES_H_
    #define SYSTEM_TYPES_H_

    #include <SFML/Audio.h>

    #include "my_json.h"
    #include "my_map.h"
    #include "my_str.h"
    #include "my_vec.h"

    #include "myrpg/window.h"


typedef struct sound_s {
    sfSound *_snd;
    map_t *_map;
    str_t *_curr;
} sound_t;

typedef struct music_s {
    sfMusic *_msc;
} music_t;

typedef struct save_s {
    char *dest;
    int slot_idx;
    sfClock *_clock;

    json_elem_t *json;
} save_t;


typedef struct system_s {
    char const *config_file;
    char const *name;
    size_t id;
    sfBool active;

    union {
        save_t save;
        sound_t sound;
        music_t music;
    } self;

    void (*init)(json_elem_t *, struct system_s *);
    void (*run)(win_t *, struct system_s *);
    void (*destroy)(struct system_s *);
} system_t;


#endif /* !SYSTEM_TYPES_H_ */
