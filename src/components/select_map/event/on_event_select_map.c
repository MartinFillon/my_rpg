/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** on hover select map
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static const int LOCKED[] = {
    MAIN_CHARACTER, HUB_VIGNETTE, GAME_MENU_ICON, GAME_SETTINGS_ICON, -1,
};

void on_click_select_map(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    if (c->id == SELECT_MAP_BACK) {
        switch_scene(w, HUB);
        move_scene_components(w, LOCKED, (sfVector2f){0, -200});
        return;
    }

    int tile_idx = 0;
    switch (c->id) {
        case SELECT_MAP_PLANET_1: tile_idx = 0; break;
        case SELECT_MAP_PLANET_2: tile_idx = 1; break;
        case SELECT_MAP_PLANET_3: tile_idx = 2; break;
    }
    w->c[GAME_PROCEDURAL_MAP_ENEMYS].self.enemy.tile_set_idx = tile_idx;
    generate_first_chunk(&w->c[GAME_PROCEDURAL_MAP], tile_idx);
    switch_scene(w, PROCEDURAL_MAP);
}
