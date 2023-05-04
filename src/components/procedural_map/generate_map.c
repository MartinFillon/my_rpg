/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** procedural test
*/

#include "my_stdlib.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/components/component_ids.h"

static const sfUint32 WHITE = 0xFFFFFFFF;
static const int CHUNK_S = 2000;
static const sfIntRect VIEWPORT = {0, 0, 1920, 1080};

static void add_chunk_to_map(
    procedural_map_t *map, sfVector2f pos, sfVector2i origin, sfVector2i map_p
)
{
    chunk_t chunk = generate_procedural_chunk(
        map->_seed, origin, map->_tiles[map->_tile_idx]
    );

    chunk._map_pos = map_p;
    chunk._origin = origin;
    chunk._bounds.left = pos.x;
    chunk._bounds.top = pos.y;
    chunk._bounds.width = CHUNK_S;
    chunk._bounds.height = CHUNK_S;

    sfSprite_setPosition(chunk._spr, pos);
    vec_pushback(&map->chunks, &chunk);
}

// clang-format off
void generate_new_chunk(procedural_map_t *map, chunk_t *c, sfIntRect inter)
{
    int x = c->_map_pos.x, y = c->_map_pos.y;
    int left = c->_bounds.left, top = c->_bounds.top;
    sfVector2f BND[4] = {
        {left - CHUNK_S, top}, {left + CHUNK_S, top},
        {left, top - CHUNK_S}, {left, top + CHUNK_S}};
    sfVector2i ORIG[4] = {
        {c->_origin.x - 20, c->_origin.y}, {c->_origin.x + 20, c->_origin.y},
        {c->_origin.x, c->_origin.y - 20}, {c->_origin.x, c->_origin.y + 20}};
    sfBool CONDS[4] = {
        (inter.left > 0), (inter.left == 0 && inter.width < VIEWPORT.width),
        (inter.top > 0), (inter.top == 0 && inter.height < VIEWPORT.height)};
    sfVector2i POS[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};

    for (int i = 0; i < 4; ++i)
        if (!map->_map[POS[i].y][POS[i].x] && CONDS[i]) {
            add_chunk_to_map(map, BND[i], ORIG[i], POS[i]);
            map->_map[POS[i].y][POS[i].x] = 1;
            break;
        }
}

static sfBool remove_invalid_first_chunk(procedural_map_t *map)
{
    sfBool invalid = sfFalse;
    int start = CHUNK_S / 2 - 100;
    int end = CHUNK_S / 2 + 100;
    chunk_t *c = &VEC_LAST(map->chunks);

    for (int y = start; y < end; ++y)
        for (int x = start; x < end; ++x)
            invalid |=
                (sfColor_toInteger(sfImage_getPixel(c->_alpha, x, y)) == WHITE);

    if (invalid) {
        destroy_chunk(c);
        vec_popback(map->chunks);
    }

    return invalid;
}

void generate_first_chunk(component_t *c, int tile_idx)
{
    c->self.proc_map._tile_idx = tile_idx;
    sfVector2i init_origin = {1000, 1000};
    sfVector2f pos = {-40, -460};
    sfVector2i map_p = {500, 500};

    do {
        c->self.proc_map._seed = rand() % 256;
        add_chunk_to_map(&c->self.proc_map, pos, init_origin, map_p);
    } while (remove_invalid_first_chunk(&c->self.proc_map));

    c->self.proc_map._map[map_p.y][map_p.x] = 1;
}
