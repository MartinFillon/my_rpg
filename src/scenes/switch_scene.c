/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** scene manager
*/

#include "myrpg/components/defs.h"
#include "myrpg/scenes/scene_list.h"

static void reset_events(win_t *w)
{
    for (size_t i = 0; i < NB_COMP; ++i) {
        if (w->c[i].show)
            continue;

        if (w->c[i]._is_clicked && w->c[i].on_release != NULL)
            w->c[i].on_release(w, &w->c[i]);
        w->c[i]._is_clicked = sfFalse;

        if (w->c[i]._is_hovered && w->c[i].on_leave != NULL)
            w->c[i].on_leave(w, &w->c[i]);
        w->c[i]._is_hovered = sfFalse;
    }
}

void switch_scene(win_t *w, int new_scene)
{
    for (int i = 0; SCENE_LIST[w->current_scene].components[i] != -1; ++i) {
        w->c[SCENE_LIST[w->current_scene].components[i]].show = sfFalse;
    }
    for (int i = 0; SCENE_LIST[new_scene].components[i] != -1; ++i) {
        w->c[SCENE_LIST[new_scene].components[i]].show = sfTrue;
    }
    w->current_scene = new_scene;
    reset_events(w);
}
