/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** init_stats
*/

#include "myrpg/components/types.h"
#include "myrpg/window.h"

void init_stats(json_elem_t *j, struct stats_s *s)
{
    s->hp = json_get_number(j, 2, "stats", "hp");
    s->def = json_get_number(j, 2, "stats", "def");
    s->atk = json_get_number(j, 2, "stats", "atk");
    s->atk_speed = json_get_number(j, 2, "stats", "atk_speed");
}
