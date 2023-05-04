/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy sprite
*/

#include "my_stdlib.h"
#include "my_stdio.h"

#include "myrpg/components/defs.h"

void destroy_npc(component_t *c)
{
    destroy_sprite(c);

    if (c->self.npc._interact && c->self.npc.dialog_filepath)
        free(c->self.npc.dialog_filepath);
}
