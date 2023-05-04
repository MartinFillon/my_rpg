/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** interact
*/

#include "my_utils.h"

#include "myrpg/components/defs.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"
#include "myrpg/scenes/scene_list.h"

static const int DIST = POW2(100);

static void open_shop(win_t *w, int i, scene_list_t scene)
{
    if (w->c[scene.components[i]].id == HUB_BETH) {
        switch_scene(w, SHOP);
    }
}

void character_interact(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    if (!sfKeyboard_isKeyPressed(w->settings.interact))
        return;

    scene_list_t scene = SCENE_LIST[w->current_scene];

    for (size_t i = 0; scene.components[i] != -1; i++) {
        if (w->c[scene.components[i]].type == NPC &&
            w->c[scene.components[i]].self.npc._interact &&
            component_distance_pow2(c, &w->c[scene.components[i]]) < DIST) {
            open_shop(w, i, scene);
            register_dialog(
                w, w->c[scene.components[i]].self.npc.dialog_filepath,
                &w->c[DIALOG_RENDERER]
            );
        }
    }
}
