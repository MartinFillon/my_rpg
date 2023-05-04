/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** init_npc
*/

#include "my_json.h"
#include "my_stdio.h"

#include "myrpg/components/defs.h"
#include "myrpg/window.h"

void init_npc(json_elem_t *j, component_t *c)
{
    init_sprite(j, c);
    c->self.npc._interact = json_get_bool(j, 1, "interact");

    c->self.npc.dialog_filepath = (c->self.npc._interact)
        ? my_strdup(str_tocstr(json_get_string(j, 1, "dialog")))
        : NULL;
}
