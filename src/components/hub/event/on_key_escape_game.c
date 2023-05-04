/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** on escape game
*/

#include "my_str.h"

#include "myrpg/components/defs.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

void on_key_escape_game(win_t *w, component_t *c, sfEvent *e)
{
    if (e->key.code != sfKeyEscape)
        return;

    if (c->id == HUB_MAP || c->id == GAME_PROCEDURAL_MAP) {
        pipe_write(STR("previous_scene"), w->current_scene);
        switch_scene(w, GAME_MENU);
    }
}
