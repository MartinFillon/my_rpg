/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** systems
*/

#include "my_json.h"
#include "my_map.h"
#include "my_stdio.h"
#include "my_stdlib.h"

#include "myrpg/window.h"
#include "myrpg/systems/system_ids.h"
#include "myrpg/systems/system_list.h"

void init_systems(win_t *w)
{
    w->s = malloc(sizeof(system_t) * NB_SYSTEMS);
    json_elem_t *json = NULL;

    for (size_t i = 0; i < NB_SYSTEMS; i++) {
        w->s[i] = SYSTEMS[i];
        if (w->s[i].config_file == NULL)
            continue;
        json = json_from_file(w->s[i].config_file);
        if (!json) {
            my_dprintf(2, "Error: %s not found\n", w->s[i].config_file);
            continue;
        }
        if (w->s[i].init)
            w->s[i].init(json, &w->s[i]);
        json_free(json);
    }
}

void run_systems(win_t *w)
{
    for (size_t i = 0; i < NB_SYSTEMS; i++)
        if (w->s[i].active && w->s[i].run)
            w->s[i].run(w, &w->s[i]);
}

void destroy_systems(win_t *w)
{
    for (size_t i = 0; i < NB_SYSTEMS; i++)
        if (w->s[i].destroy)
            w->s[i].destroy(&w->s[i]);

    free(w->s);
}
