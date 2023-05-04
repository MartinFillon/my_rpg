/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** handle enemy damage
*/

#include <stdio.h>
#include "my_stdio.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static void clear_enemies(win_t *w)
{
    enemy_t *e = &w->c[GAME_PROCEDURAL_MAP_ENEMYS].self.enemy;

    vec_clear(e->_bounds);
    vec_clear(e->_stats);
    vec_clear(e->_enemies);
}

sfBool handle_enemy_damage(win_t *w, double damage)
{
    component_t *c = &w->c[MAIN_CHARACTER];
    double d = MAX(damage - c->self.character.stats.def, 0);

    c->self.character.stats.hp -= d;
    if (c->self.character.stats.hp <= 0) {
        c->self.character.stats.hp = 100;
        c->self.character.deaths++;

        clear_enemies(w);
        clear_procedural_map(w);
        switch_scene(w, DEAD);
        return sfTrue;
    }
    return sfFalse;
}
