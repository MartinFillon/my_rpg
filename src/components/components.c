/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** components
*/

#include "my_json.h"
#include "my_stdio.h"
#include "my_stdlib.h"

#include "myrpg/callbacks/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/components/component_list.h"

static void memset_component(component_t *c)
{
    c->_is_clicked = sfFalse;
    c->_is_hovered = sfFalse;
    c->bounds = (sfFloatRect){0, 0, 0, 0};

    my_memset(&c->self, 0, sizeof(c->self));

    c->on_click = NULL;
    c->on_release = NULL;
    c->on_hover = NULL;
    c->on_leave = NULL;
    c->on_key = NULL;
    c->on_custom = NULL;
}

void init_components(win_t *w)
{
    w->c = malloc(sizeof(component_t) * NB_COMP);
    map_t *callbacks = init_callbacks();
    json_elem_t *json;

    for (size_t i = 0; i < NB_COMP; i++) {
        w->c[i] = COMPONENTS[i];
        memset_component(&w->c[i]);
        json = json_from_file(w->c[i].config_file);
        if (!json) {
            my_dprintf(2, "Error: %s not found\n", w->c[i].config_file);
            continue;
        }
        if (w->c[i].init != NULL)
            w->c[i].init(json, &w->c[i]);
        set_callbacks(json, &w->c[i], callbacks);
        json_free(json);
    }
    map_free(callbacks, NULL);
}

void draw_components(win_t *w)
{
    for (size_t i = 0; i < NB_COMP; ++i)
        if (w->c[i].draw != NULL && w->c[i].show)
            w->c[i].draw(w, &w->c[i]);
}

void destroy_components(win_t *w)
{
    for (size_t i = 0; i < NB_COMP; ++i)
        if (w->c[i].destroy != NULL)
            w->c[i].destroy(&w->c[i]);

    free(w->c);
}
