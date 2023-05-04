/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <SFML/Config.h>
    #include <SFML/Graphics.h>

    #include "my_cstr.h"
    #include "my_json.h"
    #include "my_utils.h"


typedef struct {
    float sound_vol;
    float music_vol;
    unsigned int fps;
    sfBool fullscreen;

    sfKeyCode interact;
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode left;
    sfKeyCode right;
} settings_t;

typedef struct component_s component_t;
typedef struct system_s system_t;

typedef struct {
    sfRenderWindow *self;
    sfView *_view;

    sfFont *font;
    sfClock *clock;
    sfVector2u size;

    int current_scene;
    sfBool stop_propagation;

    json_elem_t *config;
    settings_t settings;
    component_t *c;
    system_t *s;
} win_t;


// WINDOW
win_t *init_window(char const *);
void win_destroy(win_t *);
void win_resize(win_t *, sfEvent *);
// !WINDOW


// COMPONENTS
void init_components(win_t *);
void draw_components(win_t *);
void destroy_components(win_t *);
// !COMPONENTS


// SYSTEMS
void init_systems(win_t *);
void destroy_systems(win_t *);
void run_systems(win_t *);
// !SYSTEMS

// SOUND
void play_sound(system_t *, str_t *);
// !SOUND

// SETTINGS
void init_settings(win_t *);
void apply_settings(win_t *);
void update_json(win_t *);
void set_keys(win_t *);
// !SETTINGS


// DIALOG
void register_dialog(win_t *, char const *, component_t *);
// !DIALOG


#endif /* !WINDOW_H_ */
