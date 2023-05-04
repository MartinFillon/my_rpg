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

static const float FREQ = 0.1;
static const int DEPTH = 2;
static const int NB_TILES = 7;
static const int TILE_SIZE = 100;
static const sfVector2f CHUNK_SIZE = {20, 20};

static void draw_bound_in_map(sfImage *map, sfVector2i map_p)
{
    int map_x = map_p.x;
    int map_y = map_p.y;

    for (int y = 0; y < TILE_SIZE; ++y)
        for (int x = 0; x < TILE_SIZE; ++x)
            sfImage_setPixel(
                map, map_x * TILE_SIZE + x, map_y * TILE_SIZE + y, sfWhite
            );
}

static void draw_tile_in_map(
    sfImage *map, sfImage *tiles, sfVector2i map_p, int tile_idx
)
{
    int map_x = map_p.x;
    int map_y = map_p.y;

    for (int y = 0; y < TILE_SIZE; ++y)
        for (int x = 0; x < TILE_SIZE; ++x)
            sfImage_setPixel(
                map, map_x * TILE_SIZE + x, map_y * TILE_SIZE + y,
                sfImage_getPixel(tiles, tile_idx * TILE_SIZE + x, y)
            );
}

static chunk_t create_game_map(sfImage UNUSED *map, sfImage *bounds)
{
    chunk_t ret = {
        ._alpha = bounds,
        ._bounds = {0},
        ._spr = sfSprite_create(),
        ._tex = sfTexture_createFromImage(map, NULL),
    };
    sfSprite_setTexture(ret._spr, ret._tex, sfFalse);
    sfImage_destroy(map);

    return ret;
}

chunk_t generate_procedural_chunk(
    int seed, sfVector2i origin, char const *tile_path
)
{
    int tile_idx = 0;
    sfVector2i img_s = {CHUNK_SIZE.x * TILE_SIZE, CHUNK_SIZE.y * TILE_SIZE};
    sfImage *map = sfImage_createFromColor(img_s.x, img_s.y, sfWhite);
    sfImage *bounds = sfImage_createFromColor(img_s.x, img_s.y, sfBlack);
    sfImage *tiles = sfImage_createFromFile(tile_path);
    sfVector2i perlin_p = {0};

    for (sfVector2i p = {0, 0}; p.y < CHUNK_SIZE.y; p.y++) {
        for (p.x = 0; p.x < CHUNK_SIZE.x; p.x++) {
            perlin_p = (sfVector2i){origin.x + p.x, origin.y + p.y};
            tile_idx = MAX(
                perlin2d(perlin_p, FREQ, DEPTH, seed) * (NB_TILES + 2) - 2, 0
            );
            (tile_idx == 0) ? draw_bound_in_map(bounds, p) : 0;
            draw_tile_in_map(map, tiles, p, tile_idx);
        }
    }
    sfImage_destroy(tiles);
    return create_game_map(map, bounds);
}
