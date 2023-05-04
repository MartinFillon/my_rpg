/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** spawn enemies
*/

#include "my_stdlib.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

static const sfIntRect ENEMY_BOUNDS = {0, 0, 125, 162};

static sfIntRect set_positions(sfVector2u size)
{
    sfIntRect pos;
    size_t sign_x = rand() % 2;
    size_t sign_y = rand() % 2;
    size_t x = rand() % 10;
    size_t y = rand() % 10;

    pos.left = (sign_x) ? size.x + x : -x;
    pos.top = (sign_y) ? size.y + y : -y;
    pos.width = 125;
    pos.height = 162;
    return pos;
}

static void register_enemy(win_t *w, enemy_t *e)
{
    anim_sprite_t tmp;
    sfIntRect bounds = set_positions(w->size);
    size_t spr = rand() % 5;
    struct stats_s stats = {
        100, rand() % ((e->tile_set_idx + 1) * 30),
        rand() % ((e->tile_set_idx + 1) * 30), rand() % 100};

    tmp._spr = e->_sprs[e->tile_set_idx]->data[spr];
    tmp._rect = ENEMY_BOUNDS;
    tmp._anim_state = ANIM_FINISHED;
    tmp._clock = sfClock_create();
    vec_pushback(&e->_enemies, &tmp);
    vec_pushback(&e->_bounds, &bounds);
    vec_pushback(&e->_stats, &stats);
    vec_pushback(&e->_directions, &(sfVector2i){0, 0});
    vec_pushback(&e->_paths, &(int){0});
}

void spawn_enemies(win_t *w, enemy_t *e)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(e->spawn_clock)) >
        e->spawn_interval) {
        sfClock_restart(e->spawn_clock);
        for (size_t i = 0; i < e->spawn_number; i++)
            register_enemy(w, e);
    }
}
