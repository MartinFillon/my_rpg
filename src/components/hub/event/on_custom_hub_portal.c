/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** on custom portal
*/

#include "myrpg/components/defs.h"
#include "myrpg/events.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static const int DIST = POW2(100);

void on_custom_hub_portal(win_t *w, component_t UNUSED *c, sfEvent *e)
{
    if (w->c[MAIN_CHARACTER].self.character.quest == 1)
        return;
    on_custom_main_menu_portal(w, c, e);

    if (component_distance_pow2(c, &w->c[MAIN_CHARACTER]) < DIST) {
        switch_scene(w, SELECT_MAP);
    }
}
