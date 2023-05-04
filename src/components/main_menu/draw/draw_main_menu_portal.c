/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** draw_portal
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static void animate_portal(win_t *w, component_t *c)
{
    sfVector2f scale = sfSprite_getScale(c->self.anim_sprite._spr);

    if (scale.x > 4.0 && c->self.anim_sprite._anim_state == ANIM_FORWARD) {
        c->self.anim_sprite._anim_state = ANIM_BACKWARD;
        int dest = pipe_pop(STR("next_scene"));
        switch_scene(w, (dest != -1) ? dest : NONE);
    }
    if (scale.x < 1.0 && c->self.anim_sprite._anim_state == ANIM_BACKWARD) {
        c->self.anim_sprite._anim_state = ANIM_FINISHED;
        sfSprite_setScale(c->self.anim_sprite._spr, (sfVector2f){1, 1});
    }

    if (c->self.anim_sprite._anim_state == ANIM_FORWARD) {
        sfSprite_scale(c->self.anim_sprite._spr, (sfVector2f){1.02, 1.02});
    } else {
        sfSprite_scale(c->self.anim_sprite._spr, (sfVector2f){0.98, 0.98});
    }
}

void draw_main_menu_portal(win_t *w, component_t *c)
{
    sfTime elapsed = sfClock_getElapsedTime(c->self.anim_sprite._clock);

    if (sfTime_asSeconds(elapsed) > 0.01) {
        if (c->self.anim_sprite._anim_state > ANIM_FINISHED)
            animate_portal(w, c);

        sfSprite_rotate(c->self.anim_sprite._spr, 1.5);
        sfClock_restart(c->self.anim_sprite._clock);
    }

    sfRenderWindow_drawSprite(w->self, c->self.anim_sprite._spr, NULL);
}
