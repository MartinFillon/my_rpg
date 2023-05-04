/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** click
*/

#include "myrpg/components/defs.h"
#include "myrpg/events.h"
#include "myrpg/components/component_ids.h"

void click_middleware(win_t *w, sfEvent *event)
{
    sfVector2i mouse = get_mouse_pos(w, event);

    for (long i = NB_COMP - 1; i >= 0 && !w->stop_propagation; --i) {
        if (!w->c[i].show || w->c[i]._is_clicked ||
            !sfFloatRect_contains(&w->c[i].bounds, mouse.x, mouse.y))
            continue;

        w->c[i]._is_clicked = sfTrue;
        if (w->c[i].on_click != NULL)
            w->c[i].on_click(w, &w->c[i], event);
    }
}
