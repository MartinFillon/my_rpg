/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init procedural map
*/

#include "my_json.h"
#include "my_stdlib.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"

void init_procedural_map(json_elem_t *j, component_t *c)
{
    vec_json_t *tiles = json_get_array(j, 1, "tiles");

    c->self.proc_map.chunks = vec_create(100, sizeof(chunk_t));
    c->self.proc_map._clock = sfClock_create();
    c->self.proc_map._tile_idx = 0;

    c->self.proc_map._tiles = malloc(sizeof(char *) * (tiles->size + 1));
    c->self.proc_map._tiles[tiles->size] = NULL;
    for (size_t i = 0; i < tiles->size; ++i)
        c->self.proc_map._tiles[i] =
            my_strdup(tiles->data[i]->value.string->data);

    c->self.proc_map._map = malloc(sizeof(char *) * (1000 + 1));
    c->self.proc_map._map[1000] = NULL;
    for (size_t i = 0; i < 1000; ++i)
        c->self.proc_map._map[i] = my_calloc(1000, sizeof(char));
}
