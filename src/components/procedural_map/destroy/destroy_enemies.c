/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** destroy enemies
*/

#include "my_json.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"

static void free_anims(vec_anim_sprite_t *enemies)
{
    for (size_t i = 0; i < enemies->size; ++i)
        sfClock_destroy(enemies->data[i]._clock);
    free(enemies);
}

void destroy_enemies(component_t *c)
{
    enemy_t *e = &c->self.enemy;

    free_anims(e->_enemies);
    vec_free_fn(e->_sprs[0], (void (*)(void *)) & sfSprite_destroy);
    vec_free_fn(e->_sprs[1], (void (*)(void *)) & sfSprite_destroy);
    vec_free_fn(e->_sprs[2], (void (*)(void *)) & sfSprite_destroy);
    vec_free_fn(e->_texs[0], (void (*)(void *)) & sfTexture_destroy);
    vec_free_fn(e->_texs[1], (void (*)(void *)) & sfTexture_destroy);
    vec_free_fn(e->_texs[2], (void (*)(void *)) & sfTexture_destroy);
    my_vfree(4, e->_sprs, e->_texs, e->_bounds, e->_stats);
    sfClock_destroy(e->spawn_clock);
}
