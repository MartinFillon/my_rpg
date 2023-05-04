/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** key
*/

#include "myrpg/components/types.h"
#include "myrpg/components/component_ids.h"

void key_middleware(win_t *w, sfEvent *event)
{
    for (long i = NB_COMP - 1; i >= 0 && !w->stop_propagation; --i) {
        if (w->c[i].on_key != NULL && w->c[i].show) {
            w->c[i].on_key(w, &w->c[i], event);
        }
    }
}
