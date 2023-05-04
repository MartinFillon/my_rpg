/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** move scene components
*/

#include "myrpg/components/types.h"
#include "myrpg/window.h"
#include "myrpg/components/types.h"
#include "myrpg/components/defs.h"
#include "myrpg/scenes/scene_list.h"

static void move_mapper(component_t *c)
{
    sfVector2f pos = {c->bounds.left, c->bounds.top};

    switch (c->type) {
        case ANIM_SPRITE:
            sfSprite_setPosition(c->self.anim_sprite._spr, pos);
            break;
        case ENEMY:
        case NPC:
        case SPRITE: sfSprite_setPosition(c->self.sprite._spr, pos); break;
        case GAME_MAP: sfSprite_setPosition(c->self.map._spr, pos); break;
    }
}

static int is_excluded(int id, int const *exclude)
{
    for (int j = 0; exclude[j] != -1; ++j)
        if (id == exclude[j])
            return 1;
    return 0;
}

void move_scene_components(win_t *w, int const *exclude, sfVector2f pos)
{
    int scene = w->current_scene;
    component_t *comp = NULL;

    for (int i = 0; SCENE_LIST[scene].components[i] != -1; ++i) {
        comp = &w->c[SCENE_LIST[scene].components[i]];

        if (is_excluded(comp->id, exclude))
            continue;

        comp->bounds.left += pos.x;
        comp->bounds.top += pos.y;

        move_mapper(comp);
    }
}
