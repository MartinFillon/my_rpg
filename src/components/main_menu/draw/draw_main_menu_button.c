/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw buttons with animation
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/component_ids.h"

static const int PLAY_BTN_LEFT = 520;
static const int PLAY_BTN_RIGHT = 320;

static const int SETTINGS_BTN_LEFT = 540;
static const int SETTINGS_BTN_RIGHT = 340;

static const int HELP_BTN_LEFT = 900;
static const int HELP_BTN_RIGHT = 1100;

static const int QUIT_BTN_LEFT = 880;
static const int QUIT_BTN_RIGHT = 1080;

static void retract_button(component_t *c)
{
    if (c->id == MAIN_MENU_PLAY_BTN && c->bounds.left < PLAY_BTN_LEFT)
        c->bounds.left += 8;
    if (c->id == MAIN_MENU_SETTINGS_BTN && c->bounds.left < SETTINGS_BTN_LEFT)
        c->bounds.left += 8;
    if (c->id == MAIN_MENU_HELP_BTN && c->bounds.left > HELP_BTN_LEFT)
        c->bounds.left -= 8;
    if (c->id == MAIN_MENU_QUIT_BTN && c->bounds.left > QUIT_BTN_LEFT)
        c->bounds.left -= 8;
}

static void expand_button(component_t *c)
{
    if (c->id == MAIN_MENU_PLAY_BTN && c->bounds.left > PLAY_BTN_RIGHT)
        c->bounds.left -= 8;
    if (c->id == MAIN_MENU_SETTINGS_BTN && c->bounds.left > SETTINGS_BTN_RIGHT)
        c->bounds.left -= 8;
    if (c->id == MAIN_MENU_HELP_BTN && c->bounds.left < HELP_BTN_RIGHT)
        c->bounds.left += 8;
    if (c->id == MAIN_MENU_QUIT_BTN && c->bounds.left < QUIT_BTN_RIGHT)
        c->bounds.left += 8;
}

void draw_main_menu_button(win_t *w, component_t *c)
{
    sfTime elapsed = sfClock_getElapsedTime(c->self.anim_sprite._clock);

    if (sfTime_asSeconds(elapsed) > 0.001) {
        sfClock_restart(c->self.anim_sprite._clock);

        (c->_is_hovered) ? expand_button(c) : retract_button(c);

        sfSprite_setPosition(
            c->self.anim_sprite._spr,
            (sfVector2f){c->bounds.left, c->bounds.top}
        );
    }

    sfRenderWindow_drawSprite(w->self, c->self.anim_sprite._spr, NULL);
}
