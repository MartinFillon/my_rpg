/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** utils init_bounds
*/

#include "my_json.h"

#include "myrpg/components/defs.h"

void init_component_bounds(component_t *c, json_elem_t *json)
{
    c->bounds = (sfFloatRect){
        json_get_number(json, 2, "bounds", "left"),
        json_get_number(json, 2, "bounds", "top"),
        json_get_number(json, 2, "bounds", "width"),
        json_get_number(json, 2, "bounds", "height"),
    };
}
