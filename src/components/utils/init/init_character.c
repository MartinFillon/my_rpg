/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** init_character
*/

#include "my_json.h"

#include "myrpg/components/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/types.h"

void init_character(json_elem_t *j, component_t *c)
{
    init_anim_sprite(j, c);
    init_stats(j, &c->self.character.stats);
    c->self.character.deaths = 0;
    c->self.character.kills = 0;
    c->self.character.coins = 0;
    c->self.character.quest = 1;
}
