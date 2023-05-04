/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** event handler
*/

#include "myrpg/components/defs.h"
#include "myrpg/events.h"
#include "myrpg/components/component_ids.h"

static void run_custom_events(win_t *w, sfEvent *event)
{
    for (size_t i = 0; i < NB_COMP; ++i)
        if (w->c[i].on_custom != NULL && w->c[i].show)
            w->c[i].on_custom(w, &w->c[i], event);
}

static void known_events(win_t *w, sfEvent *event)
{
    switch (event->type) {
        case sfEvtMouseButtonPressed: click_middleware(w, event); break;
        case sfEvtKeyPressed: key_middleware(w, event); break;
        case sfEvtMouseMoved:
            leave_middleware(w, event);
            hover_middleware(w, event);
            break;
        case sfEvtMouseButtonReleased: release_middleware(w); break;
        default: break;
    }
}

void handle_events(win_t *w)
{
    sfEvent event = {0};

    while (sfRenderWindow_pollEvent(w->self, &event)) {
        run_custom_events(w, &event);

        known_events(w, &event);

        if (event.type == sfEvtResized)
            win_resize(w, &event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->self);

        w->stop_propagation = sfFalse;
    }
}
