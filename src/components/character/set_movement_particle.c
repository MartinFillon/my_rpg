/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** set_movement_particle
*/

#include "my_stdlib.h"

#include "myrpg/components/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

static sfIntRect RECTS[4] = {
    {0, 0, 250, 250},
    {0, 250, 250, 250},
    {250, 0, 250, 250},
    {250, 250, 250, 250},
};

static void set_new_bounds(component_t *c, sfVector2f dir)
{
    if (dir.x == 0 && dir.y > 0) {
        c->bounds.left = 899 + 122.0 / 2 - c->bounds.width / 2;
        c->bounds.top = 461 + 155;
    }
    if (dir.x == 0 && dir.y < 0)
        c->show = sfFalse;
    if (dir.x > 0 && dir.y == 0) {
        c->bounds.left = 899 + c->bounds.width + 20;
        c->bounds.top = 461 + 110;
    }
    if (dir.x < 0 && dir.y == 0) {
        c->bounds.left = 880;
        c->bounds.top = 461 + 110;
    }
}

void set_movement_particle(win_t *w, sfVector2f dir)
{
    component_t *c = &w->c[MOVING_SMOKE_PARTICLE];

    c->show = sfTrue;
    sfSprite_setScale(c->self.sprite._spr, (sfVector2f){0.25, 0.25});
    c->bounds.height = 250 * 0.25;
    c->bounds.width = 250 * 0.25;
    set_new_bounds(c, dir);
    c->self.sprite._rect = RECTS[rand() % 4];
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
    sfSprite_setPosition(
        c->self.sprite._spr, (sfVector2f){c->bounds.left, c->bounds.top}
    );
}
