/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** draw_portal
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/component_ids.h"

void draw_portal_gun(win_t *w, component_t *c)
{
    if (w->c[MAIN_CHARACTER].self.character.quest > 1)
        return;
    draw_sprite(w, c);
}

void draw_portal(win_t *w, component_t *c)
{
    if (w->c[MAIN_CHARACTER].self.character.quest == 1)
        return;
    draw_main_menu_portal(w, c);
}
