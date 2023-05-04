/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** draw_projectile
*/

#include <SFML/Graphics/Types.h>
#include <stddef.h>
#include <stdio.h>
#include "my_stdlib.h"
#include "my_utils.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_list.h"

static void verify_death(win_t *w, size_t i)
{
    if (w->c[GAME_PROCEDURAL_MAP_ENEMYS].self.enemy._stats->data[i].hp <= 0) {
        w->c[GAME_PROCEDURAL_MAP_ENEMYS].self.enemy._stats->data[i].hp = 0;
        w->c[MAIN_CHARACTER].self.character.kills++;
        w->c[MAIN_CHARACTER].self.character.coins += 20;
        char *str = my_itoa(w->c[MAIN_CHARACTER].self.character.coins);
        sfText_setString(w->c[SHOP_MONEY_COUNTER].self.text._txt, str);
        set_bestiary(w, i);
    }
}

static void check_collision(win_t *w, projectile_data_t *elem)
{
    vec_stat_t *stats = w->c[GAME_PROCEDURAL_MAP_ENEMYS].self.enemy._stats;
    vec_bounds_t *pos = w->c[GAME_PROCEDURAL_MAP_ENEMYS].self.enemy._bounds;
    double atk = 0;
    double main_atk = w->c[MAIN_CHARACTER].self.character.stats.atk;

    for (size_t i = 0; i < pos->size; i++) {
        if (stats->data[i].hp > 0 &&
            sfIntRect_contains(&pos->data[i], elem->pos.x, elem->pos.y)) {
            elem->_active = sfFalse;
            atk = MAX(main_atk - stats->data[i].def, 0);
            stats->data[i].hp -= atk;
            verify_death(w, i);
            return;
        }
    }
}

static void set_projectiles_position(
    win_t *w, projectile_data_t *elem, component_t *c
)
{
    if (!elem->_active)
        return;

    elem->pos.y += elem->dir.y;
    elem->pos.x += elem->dir.x;

    if (POW2(elem->pos.x - elem->origin.x) +
            POW2(elem->pos.y - elem->origin.y) >
        POW2(c->self.projectiles.max_travel_distance)) {
        elem->_active = sfFalse;
    }
    check_collision(w, elem);
}

void draw_projectiles(win_t *w, component_t *c)
{
    projectile_data_t *elem;
    sfTime time = sfClock_getElapsedTime(c->self.projectiles._clock);

    if (sfTime_asSeconds(time) > 0.01) {
        for (size_t i = 0; i < c->self.projectiles.data->size; i++) {
            elem = &c->self.projectiles.data->data[i];
            set_projectiles_position(w, elem, c);
        }
        sfClock_restart(c->self.projectiles._clock);
    }
    for (size_t i = 0; i < c->self.projectiles.data->size; i++) {
        elem = &c->self.projectiles.data->data[i];
        if (!elem->_active)
            continue;
        sfSprite_setPosition(c->self.projectiles.sprite._spr, elem->pos);
        sfSprite_setRotation(c->self.projectiles.sprite._spr, elem->angle);
        sfRenderWindow_drawSprite(
            w->self, c->self.projectiles.sprite._spr, NULL
        );
    }
}

void move_projectiles(win_t *w, sfVector2f pos)
{
    component_t *c = &w->c[PROJECTILE];

    for (size_t i = 0; i < c->self.projectiles.data->size; i++) {
        projectile_data_t *elem = &c->self.projectiles.data->data[i];
        if (!elem->_active)
            continue;
        elem->origin.x = elem->origin.x + pos.x;
        elem->origin.y = elem->origin.y + pos.y;
        elem->pos.x = elem->pos.x + pos.x;
        elem->pos.y = elem->pos.y + pos.y;
    }
}
