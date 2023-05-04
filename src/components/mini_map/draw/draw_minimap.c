/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw minimap
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static const int COMPS[2][10] = {
    {HUB_MAP, HUB_PORTAL, MAIN_CHARACTER, -1},
    {GAME_PROCEDURAL_MAP, GAME_PROCEDURAL_MAP_ENEMYS, MAIN_CHARACTER, -1},
};

void draw_minimap(win_t *w, component_t *c)
{
    if (w->current_scene != HUB && w->current_scene != PROCEDURAL_MAP)
        return;

    mini_map_t *mini_map = &c->self.mini_map;
    int idx = w->current_scene == HUB ? 0 : 1;

    sfRenderWindow_setView(w->self, mini_map->_view);
    sfRenderWindow_drawRectangleShape(w->self, mini_map->_bg, NULL);

    for (int i = 0; COMPS[idx][i] != -1; ++i)
        if (w->c[COMPS[idx][i]].draw != NULL && w->c[COMPS[idx][i]].show)
            w->c[COMPS[idx][i]].draw(w, &w->c[COMPS[idx][i]]);

    sfRenderWindow_setView(w->self, w->_view);
    sfRenderWindow_drawSprite(w->self, mini_map->_spr, NULL);
}
