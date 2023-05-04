/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** events
*/

#ifndef EVENTS_
    #define EVENTS_

    #include "myrpg/window.h"


// UTILS
sfVector2i get_mouse_pos(win_t *, sfEvent *);
void stop_propagation(win_t *, component_t *, sfEvent *);
// !UTILS


// MIDDLEWARES
void click_middleware(win_t *, sfEvent *);
void leave_middleware(win_t *, sfEvent *);
void key_middleware(win_t *, sfEvent *);
void hover_middleware(win_t *, sfEvent *);
void release_middleware(win_t *);
// !MIDDLEWARES


void handle_events(win_t *);


#endif /* !EVENTS_ */
