/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set movement animation
*/

#include "myrpg/components/defs.h"

static const int ROADBLOACK[5] = {0, 500, 1000, 1500, 2000};

void set_movement_animation(component_t *c, int dir)
{
    sfTime elapsed = sfClock_getElapsedTime(c->self.anim_sprite._clock);
    int left = c->self.anim_sprite._rect.left;
    int width = c->self.anim_sprite._rect.width;

    if (sfTime_asSeconds(elapsed) < 0.1)
        return;
    sfClock_restart(c->self.anim_sprite._clock);
    if (left >= ROADBLOACK[dir] || left < ROADBLOACK[dir - 1]) {
        c->self.anim_sprite._rect.left = ROADBLOACK[dir - 1];
    } else {
        c->self.anim_sprite._rect.left = (left + width < ROADBLOACK[dir] - 1)
            ? left + width
            : ROADBLOACK[dir - 1];
    }
    sfSprite_setTextureRect(
        c->self.anim_sprite._spr, c->self.anim_sprite._rect
    );
}
