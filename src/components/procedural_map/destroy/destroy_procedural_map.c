/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw procedural map
*/

#include "my_stdlib.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/window.h"

void destroy_chunk(chunk_t *ch)
{
    sfImage_destroy(ch->_alpha);
    sfSprite_destroy(ch->_spr);
    sfTexture_destroy(ch->_tex);
}

void destroy_procedural_map(component_t *c)
{
    procedural_map_t *map = &c->self.proc_map;

    sfClock_destroy(map->_clock);
    for (int i = 0; map->_map[i]; ++i)
        free(map->_map[i]);
    free(map->_map);
    for (int i = 0; map->_tiles[i]; ++i)
        free(map->_tiles[i]);
    free(map->_tiles);
    for (size_t i = 0; i < map->chunks->size; ++i)
        destroy_chunk(&map->chunks->data[i]);
    free(map->chunks);
}

void clear_procedural_map(win_t *w)
{
    procedural_map_t *map = &w->c[GAME_PROCEDURAL_MAP].self.proc_map;

    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 1000; ++j)
            map->_map[i][j] = 0;
    for (size_t i = 0; i < map->chunks->size; ++i) {
        sfImage_destroy(map->chunks->data[i]._alpha);
        sfSprite_destroy(map->chunks->data[i]._spr);
        sfTexture_destroy(map->chunks->data[i]._tex);
    }
    vec_clear(map->chunks);
}
