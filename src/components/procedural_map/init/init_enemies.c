/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** init enemies
*/

#include "my_stdlib.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

static void load_sprites_and_textures(vec_json_t *enemies, component_t *c)
{
    sfSprite *spr = NULL;
    sfTexture *tex = NULL;
    size_t size = 0;

    for (size_t i = 0; i < enemies->size; i++) {
        size = enemies->data[i]->value.array->size;
        c->self.enemy._sprs[i] = vec_create(size, sizeof(sfSprite *));
        c->self.enemy._texs[i] = vec_create(size, sizeof(sfTexture *));
        for (size_t j = 0; j < enemies->data[i]->value.array->size; j++) {
            tex = sfTexture_createFromFile(
                enemies->data[i]->value.array->data[j]->value.string->data, NULL
            );
            spr = sfSprite_create();
            sfSprite_setTexture(spr, tex, sfTrue);
            vec_pushback(&c->self.enemy._texs[i], &tex);
            vec_pushback(&c->self.enemy._sprs[i], &spr);
        }
    }
}

void init_enemies(json_elem_t *j, component_t *c)
{
    vec_json_t *enemies = json_get_array(j, 1, "textures");
    c->self.enemy._texs = malloc(sizeof(vec_tex_t *) * enemies->size);
    c->self.enemy._sprs = malloc(sizeof(vec_sprite_t *) * enemies->size);
    c->self.enemy._enemies = vec_create(100, sizeof(anim_sprite_t));
    c->self.enemy._stats = vec_create(100, sizeof(struct stats_s));
    c->self.enemy._bounds = vec_create(100, sizeof(sfIntRect));
    c->self.enemy._directions = vec_create(100, sizeof(sfVector2i));
    c->self.enemy._paths = vec_create(100, sizeof(int));
    c->self.enemy.spawn_clock = sfClock_create();
    c->self.enemy.spawn_number = json_get_number(j, 1, "spawn_number");
    c->self.enemy.spawn_interval = json_get_number(j, 1, "spawn_interval");
    load_sprites_and_textures(enemies, c);
}
