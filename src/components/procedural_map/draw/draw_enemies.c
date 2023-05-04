/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** draw enemies
*/

#include "my_stdlib.h"
#include "my_vec.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/components/component_ids.h"

void draw_enemy(win_t *w, component_t *c)
{
    enemy_t *e = &c->self.enemy;

    for (size_t i = 0; i < e->_enemies->size; i++) {
        if (e->_stats->data[i].hp <= 0)
            continue;
        if (move_enemy(w, e, i))
            continue;

        anim_sprite_t *t = &e->_enemies->data[i];
        sfIntRect pos = e->_bounds->data[i];
        sfSprite_setPosition(t->_spr, (sfVector2f){pos.left, pos.top});
        sfSprite_setTextureRect(t->_spr, e->_enemies->data[i]._rect);
        sfRenderWindow_drawSprite(w->self, e->_enemies->data[i]._spr, NULL);
    }
    spawn_enemies(w, e);
}

void move_enemies_with_map(win_t *w, sfVector2f pos)
{
    enemy_t *e = &w->c[GAME_PROCEDURAL_MAP_ENEMYS].self.enemy;

    for (size_t i = 0; i < e->_bounds->size; i++) {
        e->_bounds->data[i].left += pos.x;
        e->_bounds->data[i].top += pos.y;
        sfSprite_setPosition(
            e->_enemies->data[i]._spr,
            (sfVector2f){e->_bounds->data[i].left, e->_bounds->data[i].top}
        );
    }
}
