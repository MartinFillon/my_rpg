/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** stop propagation when hovering portal
*/

#include "my_utils.h"

#include "myrpg/components/defs.h"
#include "myrpg/events.h"

static const sfVector2i CENTER = {940, 585};
static const int RADIUS = 280;

void on_custom_main_menu_portal(win_t *w, component_t UNUSED *c, sfEvent *e)
{
    if (e->type != sfEvtMouseMoved && e->type != sfEvtMouseButtonPressed)
        return;

    sfVector2i mouse = get_mouse_pos(w, e);

    if (POW2(CENTER.x - mouse.x) + POW2(CENTER.y - mouse.y) <= POW2(RADIUS)) {
        w->stop_propagation = sfTrue;
    }
}
