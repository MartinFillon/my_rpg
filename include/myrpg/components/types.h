/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** types
*/

#ifndef COMPONENTS_TYPES_H_
    #define COMPONENTS_TYPES_H_

    #include "my_json.h"
    #include "my_map.h"
    #include "my_str.h"
    #include "my_vec.h"

    #include "myrpg/window.h"


enum comp_type_e {
    ANIM_SPRITE,
    SPRITE,
    NPC,
    DIALOG,
    GAME_MAP,
    GAME_PMAP,
    GAME_MMAP,
    TEXT,
    ANIM_TEXT,
    ENEMY,
    PROJECTILES,
    QUEST,
    CHARACTER,
};

enum anim_state_e {
    ANIM_FINISHED,

    ANIM_FORWARD,
    ANIM_BACKWARD,
};

typedef struct sprite_s {
    sfSprite *_spr;
    sfTexture *_tex;
    sfIntRect _rect;
} sprite_t;

typedef struct anim_sprite_s {
    sfSprite *_spr;
    sfTexture *_tex;
    sfIntRect _rect;

    size_t _anim_state;
    sfClock *_clock;
} anim_sprite_t;

typedef struct mini_map_s {
    sfSprite *_spr;
    sfTexture *_tex;

    sfView *_view;
    sfRectangleShape *_bg;
} mini_map_t;

typedef struct game_map_s {
    sfSprite *_spr;
    sfTexture *_tex;
    sfIntRect _rect;

    sfClock *_clock;
    sfImage *_alpha;
} game_map_t;

typedef struct chunk_s {
    sfSprite *_spr;
    sfTexture *_tex;
    sfImage *_alpha;
    sfIntRect _bounds;
    sfVector2i _origin;
    sfVector2i _map_pos;
} chunk_t;

VEC_DEF(chunk_t, chunk)

typedef struct procedural_map_s {
    vec_chunk_t *chunks;

    char **_map;
    sfClock *_clock;
    int _seed;
    char **_tiles;
    size_t _tile_idx;
} procedural_map_t;

typedef struct text_s {
    sfText *_txt;
    sfFont *_font;
} text_t;

typedef struct anim_text_s {
    text_t txt;
    sfClock *_clock;
    double _speed;

    json_elem_t *json;
    vec_json_t *dialog;
    str_t *sentence;
    size_t sentence_idx;
    size_t dialog_idx;
    float interval;
    float delay;
} anim_text_t;

typedef struct npc_s {
    sprite_t sprite;

    sfBool _interact;
    char *dialog_filepath;
} npc_t;

struct stats_s {
    double hp;
    double atk;
    double def;
    double atk_speed;
};

VEC_DEF(struct stats_s, stat)
VEC_DEF(anim_sprite_t, anim_sprite)
VEC_DEF(sfIntRect, bounds)
VEC_DEF(sfSprite *, sprite)
VEC_DEF(sfTexture *, tex)
VEC_DEF(sfVector2i, 2int)

typedef struct enemy_s {
    vec_anim_sprite_t *_enemies;
    vec_bounds_t *_bounds;
    vec_stat_t *_stats;
    vec_int_t *_paths;
    vec_2int_t *_directions;

    vec_sprite_t **_sprs;
    vec_tex_t **_texs;

    sfClock *spawn_clock;
    float spawn_interval;
    size_t spawn_number;
    size_t tile_set_idx;
} enemy_t;

typedef struct character_s {
    anim_sprite_t sprite;

    struct stats_s stats;
    size_t deaths;
    size_t kills;
    size_t coins;
    size_t quest;
} character_t;

typedef struct projectile_data_s {
    sfVector2f pos;
    sfVector2f dir;
    sfVector2f origin;
    sfBool _active;
    float angle;
} projectile_data_t;

VEC_DEF(projectile_data_t, projectile_data);

typedef struct projectiles_s {
    sprite_t sprite;

    vec_projectile_data_t *data;

    float max_travel_distance;
    sfClock *_clock;
} projectiles_t;

typedef struct quest_s {
    sprite_t quest_box;
    text_t quest_text;
    text_t quest_content;
    sprite_t quest_complete;
} quest_t;

VEC_DEF(quest_t, quest);

typedef struct component_s {
    const char *config_file;
    const char *name;
    size_t id;
    sfBool show;

    union {
        anim_sprite_t anim_sprite;
        sprite_t sprite;
        game_map_t map;
        mini_map_t mini_map;
        procedural_map_t proc_map;
        text_t text;
        anim_text_t dialog;
        npc_t npc;
        enemy_t enemy;
        projectiles_t projectiles;
        vec_quest_t *quests;
        character_t character;
    } self;
    size_t type;

    void (*init)(json_elem_t *, struct component_s *);
    void (*destroy)(struct component_s *);
    void (*draw)(win_t *, struct component_s *);

    sfFloatRect bounds;
    sfBool _is_hovered;
    sfBool _is_clicked;

    void (*on_click)(win_t *, struct component_s *, sfEvent *);
    void (*on_release)(win_t *, struct component_s *);
    void (*on_hover)(win_t *, struct component_s *, sfEvent *);
    void (*on_leave)(win_t *, struct component_s *);
    void (*on_key)(win_t *, struct component_s *, sfEvent *);
    void (*on_custom)(win_t *, struct component_s *, sfEvent *);
} component_t;


#endif /* !COMPONENTS_TYPES_H_ */
