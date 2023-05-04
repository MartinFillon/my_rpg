/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** stop an events propagation
*/

#include "my_stdio.h"

#include "myrpg/components/defs.h"

void stop_propagation(
    win_t UNUSED *w, component_t UNUSED *c, sfEvent UNUSED *event
)
{
    w->stop_propagation = sfTrue;
}
