/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** draw_text
*/

#include "myrpg/components/defs.h"

void draw_text(win_t *w, component_t *c)
{
    sfRenderWindow_drawText(w->self, c->self.text._txt, NULL);
}
