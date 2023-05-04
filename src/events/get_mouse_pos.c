/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** get mouse pos
*/

#include "myrpg/components/defs.h"

static const sfVector2i INIT_WIN_SIZE = {1920, 1080};

sfVector2i get_mouse_pos(win_t *w, sfEvent *e)
{
    sfVector2f mouse_pos = {-1, -1};

    switch (e->type) {
        case sfEvtMouseMoved:
            mouse_pos.x = e->mouseMove.x;
            mouse_pos.y = e->mouseMove.y;
            break;
        case sfEvtMouseButtonPressed:
            mouse_pos.x = e->mouseButton.x;
            mouse_pos.y = e->mouseButton.y;
            break;
        default:
            break;
    }

    return (sfVector2i){
        mouse_pos.x * (float)INIT_WIN_SIZE.x / (float)w->size.x,
        mouse_pos.y * (float)INIT_WIN_SIZE.y / (float)w->size.y,
    };
}
