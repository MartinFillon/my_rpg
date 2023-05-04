/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** on_click_event
*/

#include "myrpg/window.h"
#include "myrpg/components/types.h"
#include "myrpg/components/component_ids.h"

static void settings_key_up(win_t *w, component_t *c)
{
    if (c->id == SETTINGS_KEYS_UP_BOX) {
        w->c[SETTINGS_KEYS_DOWN_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_LEFT_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_RIGHT_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_INTERACT_BOX].self.sprite._rect.left = 100;
    }
}

static void settings_key_down(win_t *w, component_t *c)
{
    if (c->id == SETTINGS_KEYS_DOWN_BOX) {
        w->c[SETTINGS_KEYS_UP_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_LEFT_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_RIGHT_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_INTERACT_BOX].self.sprite._rect.left = 100;
    }
}

static void settings_key_left_and_right(win_t *w, component_t *c)
{
    if (c->id == SETTINGS_KEYS_LEFT_BOX) {
        w->c[SETTINGS_KEYS_UP_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_DOWN_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_RIGHT_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_INTERACT_BOX].self.sprite._rect.left = 100;
    }
    if (c->id == SETTINGS_KEYS_RIGHT_BOX) {
        w->c[SETTINGS_KEYS_UP_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_DOWN_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_LEFT_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_INTERACT_BOX].self.sprite._rect.left = 100;
    }
}

static void settings_key_interact(win_t *w, component_t *c)
{
    if (c->id == SETTINGS_KEYS_INTERACT_BOX) {
        w->c[SETTINGS_KEYS_UP_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_DOWN_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_LEFT_BOX].self.sprite._rect.left = 100;
        w->c[SETTINGS_KEYS_RIGHT_BOX].self.sprite._rect.left = 100;
    }
}

void on_click_key_maps(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    if (c->self.sprite._rect.left == 0)
        return;
    settings_key_up(w, c);
    settings_key_down(w, c);
    settings_key_left_and_right(w, c);
    settings_key_interact(w, c);
    c->self.sprite._rect.left = 0;
    sfSprite_setTextureRect(w->c[SETTINGS_KEYS_UP_BOX].self.sprite._spr,
        w->c[SETTINGS_KEYS_UP_BOX].self.sprite._rect);
    sfSprite_setTextureRect(w->c[SETTINGS_KEYS_DOWN_BOX].self.sprite._spr,
        w->c[SETTINGS_KEYS_DOWN_BOX].self.sprite._rect);
    sfSprite_setTextureRect(w->c[SETTINGS_KEYS_LEFT_BOX].self.sprite._spr,
        w->c[SETTINGS_KEYS_LEFT_BOX].self.sprite._rect);
    sfSprite_setTextureRect(w->c[SETTINGS_KEYS_RIGHT_BOX].self.sprite._spr,
        w->c[SETTINGS_KEYS_RIGHT_BOX].self.sprite._rect);
    sfSprite_setTextureRect(w->c[SETTINGS_KEYS_INTERACT_BOX].self.sprite._spr,
        w->c[SETTINGS_KEYS_INTERACT_BOX].self.sprite._rect);
    apply_settings(w);
}
