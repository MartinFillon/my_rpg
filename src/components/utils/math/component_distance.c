/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** check components distance
*/

#include <math.h>

#include "my_utils.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_list.h"

float component_distance_pow2(component_t *comp1, component_t *comp2)
{
    sfVector2f pos_1 = {comp1->bounds.left, comp1->bounds.top};
    sfVector2f pos_2 = {comp2->bounds.left, comp2->bounds.top};

    return POW2(pos_1.x - pos_2.x) + POW2(pos_1.y - pos_2.y);
}
