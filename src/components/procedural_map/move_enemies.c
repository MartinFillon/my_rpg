/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** move enemies
*/

#include "my_stdlib.h"
#include "my_stdio.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static const int ROADBLOACK[5] = {0, 500, 1000, 1500, 2000};

static void set_movement_animation_enemy(anim_sprite_t *t, int dir)
{
    int left = t->_rect.left;
    int width = t->_rect.width;

    if (left >= ROADBLOACK[dir] || left < ROADBLOACK[dir - 1]) {
        t->_rect.left = ROADBLOACK[dir - 1];
    } else {
        t->_rect.left = (left + width < ROADBLOACK[dir] - 1)
            ? left + width
            : ROADBLOACK[dir - 1];
    }
    sfSprite_setTextureRect(t->_spr, t->_rect);
}

static void choose_new_path(win_t *w, enemy_t *e, size_t idx)
{
    sfIntRect *pos = &e->_bounds->data[idx];
    e->_paths->data[idx] = rand() % 100 + 20;

    if (rand() % 2 == 0) {
        e->_directions->data[idx].x =
            (pos->left < (int)w->size.x / 2) ? 10 : -10;
        e->_directions->data[idx].y = 0;
    } else {
        e->_directions->data[idx].x = 0;
        e->_directions->data[idx].y =
            (pos->top < (int)w->size.y / 2) ? 10 : -10;
    }
}

static void move_enemy_in_direction(enemy_t *e, size_t idx)
{
    sfIntRect *pos = &e->_bounds->data[idx];

    e->_paths->data[idx] -= 10;
    if (e->_directions->data[idx].x != 0) {
        set_movement_animation_enemy(
            &e->_enemies->data[idx], (e->_directions->data[idx].x > 0) ? 3 : 2
        );
        pos->left += e->_directions->data[idx].x;
    } else {
        set_movement_animation_enemy(
            &e->_enemies->data[idx], (e->_directions->data[idx].y > 0) ? 1 : 4
        );
        pos->top += e->_directions->data[idx].y;
    }
}

// clang-format off
sfBool move_enemy(win_t *w, enemy_t *e, size_t idx)
{
    sfTime elapsed = sfClock_getElapsedTime(e->_enemies->data[idx]._clock);
    sfIntRect *pos = &e->_bounds->data[idx];
    sfIntRect main_char_bounds = (sfIntRect){
        w->c[MAIN_CHARACTER].bounds.left, w->c[MAIN_CHARACTER].bounds.top,
        w->c[MAIN_CHARACTER].bounds.width, w->c[MAIN_CHARACTER].bounds.height
    };

    if (sfTime_asSeconds(elapsed) < 0.1)
        return sfFalse;
    sfClock_restart(e->_enemies->data[idx]._clock);
    if (sfIntRect_intersects(pos, &main_char_bounds, NULL)) {
        if (handle_enemy_damage(w, e->_stats->data[idx].atk))
            return sfTrue;
    }
    if (e->_paths->data[idx] < 0)
        choose_new_path(w, e, idx);
    move_enemy_in_direction(e, idx);

    return sfFalse;
}
// clang-format on
