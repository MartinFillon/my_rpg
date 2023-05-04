/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw procedural map
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

static const int MOVEMENT = 10;
static const sfUint32 WHITE = 0xFFFFFFFF;
static const sfIntRect VIEWPORT = {0, 0, 1920, 1080};
static const sfVector2i DIRS[4] = {
    {0, MOVEMENT},
    {-MOVEMENT, 0},
    {MOVEMENT, 0},
    {0, -MOVEMENT},
};

// clang-format off
sfBool check_position_in_chunk(int dir, chunk_t *chunk, sfIntRect plr)
{
    sfBool is_x = (dir == 1 || dir == 2);
    plr.left -= chunk->_bounds.left;
    plr.top -= chunk->_bounds.top;
    sfVector2i inters[2] = {
        {MAX(plr.left, 0), MIN(plr.left + plr.width, 1999)},
        {MAX(plr.top, 0), MIN(plr.top + plr.height, 1999)}};
    sfVector2i inter = inters[is_x];
    sfVector2i checks[4] = {
        {0, MAX(MIN(plr.top + plr.height, 1999), 0)},
        {MAX(MIN(plr.left, 1999), 0), 0},
        {MAX(MIN(plr.left + plr.width, 1999), 0), 0},
        {0, MAX(MIN(plr.top, 1999), 0)}};
    sfVector2i check = checks[dir];

    for (int j = inter.x; j < inter.y; ++j)
        if (sfColor_toInteger(sfImage_getPixel(
                chunk->_alpha, (!is_x) ? j : check.x, (is_x) ? j : check.y
            )) == WHITE)
            return sfTrue;
    return sfFalse;
}

// clang-format on
static sfBool check_valid_pos(procedural_map_t *map, int dir)
{
    sfIntRect plr = {
        VIEWPORT.width / 2 + DIRS[dir].x - 35,
        VIEWPORT.height / 2 + DIRS[dir].y, 70, 70};

    for (size_t i = 0; i < map->chunks->size; ++i) {
        if (!sfIntRect_intersects(&map->chunks->data[i]._bounds, &plr, NULL))
            continue;
        if (check_position_in_chunk(dir, &map->chunks->data[i], plr))
            return sfTrue;
    }
    return sfFalse;
}

static void move_chunk(chunk_t *ch, int dir)
{
    ch->_bounds.left -= DIRS[dir].x;
    ch->_bounds.top -= DIRS[dir].y;
    sfVector2f pos = {ch->_bounds.left, ch->_bounds.top};

    sfSprite_setPosition(ch->_spr, pos);
}

static void catch_keyboard_evt(win_t *w, procedural_map_t *map)
{
    int KEYS[4] = {
        w->settings.down, w->settings.left, w->settings.right, w->settings.up};
    if (sfTime_asSeconds(sfClock_getElapsedTime(map->_clock)) < 0.01)
        return;
    sfClock_restart(map->_clock);
    for (int i = 0; i < 4; ++i) {
        if (!sfKeyboard_isKeyPressed(KEYS[i]) || check_valid_pos(map, i))
            continue;
        sfVector2f dir = {-DIRS[i].x, -DIRS[i].y};
        move_enemies_with_map(w, dir);
        set_movement_particle(w, dir);
        set_movement_animation(&w->c[MAIN_CHARACTER], i + 1);
        move_projectiles(w, dir);
        for (size_t j = 0; j < map->chunks->size; ++j)
            move_chunk(&map->chunks->data[j], i);
        break;
    }
}

void draw_procedural_map(win_t *w, component_t *c)
{
    chunk_t *elem = NULL;
    sfIntRect inter = {0};

    catch_keyboard_evt(w, &c->self.proc_map);
    for (size_t i = 0; i < c->self.proc_map.chunks->size; ++i) {
        elem = &c->self.proc_map.chunks->data[i];

        if (!sfIntRect_intersects(&elem->_bounds, &VIEWPORT, &inter))
            continue;

        generate_new_chunk(&c->self.proc_map, elem, inter);
        sfRenderWindow_drawSprite(w->self, elem->_spr, NULL);
    }
}
