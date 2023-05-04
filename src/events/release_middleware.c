/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** release
*/

#include "myrpg/components/types.h"
#include "myrpg/components/component_ids.h"

void release_middleware(win_t *w)
{
    for (long i = NB_COMP - 1; i >= 0; --i) {
        if (!w->c[i].show || !w->c[i]._is_clicked)
            continue;

        w->c[i]._is_clicked = sfFalse;
        if (w->c[i].on_release != NULL)
            w->c[i].on_release(w, &w->c[i]);
    }
}
