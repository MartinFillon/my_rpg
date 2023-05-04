/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** on_cutom_particle
*/

#include "myrpg/components/defs.h"
#include "myrpg/window.h"

void on_custom_particle(win_t UNUSED *w, component_t *c, sfEvent *e)
{
    if (e->type == sfEvtKeyReleased) {
        c->show = sfFalse;
    }
}
