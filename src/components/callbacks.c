/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** functions
*/

#include "my_json.h"
#include "my_map.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "myrpg/callbacks/callback_list.h"

map_t *init_callbacks(void)
{
    map_t *map = map_create(NB_CALLBACKS + 1);
    str_t *key = NULL;

    for (size_t i = 0; i < NB_CALLBACKS; i++) {
        key = str_create(CALLBACKS[i].name);
        map_set(map, key, CALLBACKS[i].callback);
        free(key);
    }

    return map;
}

void set_callbacks(json_elem_t *json, component_t *c, map_t *callbacks)
{
    str_t *on_click = json_get_string(json, 1, "on_click");
    str_t *on_hover = json_get_string(json, 1, "on_hover");
    str_t *on_release = json_get_string(json, 1, "on_release");
    str_t *on_leave = json_get_string(json, 1, "on_leave");
    str_t *on_key = json_get_string(json, 1, "on_key");
    str_t *on_custom = json_get_string(json, 1, "on_custom");

    if (on_click != NULL)
        c->on_click = map_get(callbacks, on_click);
    if (on_release != NULL)
        c->on_release = map_get(callbacks, on_release);
    if (on_hover != NULL)
        c->on_hover = map_get(callbacks, on_hover);
    if (on_leave != NULL)
        c->on_leave = map_get(callbacks, on_leave);
    if (on_key != NULL)
        c->on_key = map_get(callbacks, on_key);
    if (on_custom != NULL)
        c->on_custom = map_get(callbacks, on_custom);
}
