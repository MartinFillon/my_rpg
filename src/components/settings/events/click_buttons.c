/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** click_buttons
*/

#include "myrpg/components/defs.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static void click_settings_button_bis(
    win_t *w, component_t UNUSED *c, sfEvent UNUSED *e
)
{
    if (c->id == SETTINGS_KEY_BTN) {
        c->self.sprite._rect.left = c->self.sprite._rect.width * 2;
        w->c[SETTINGS_AUDIO_BTN].self.sprite._rect.left = 0;
        w->c[SETTINGS_VIDEO_BTN].self.sprite._rect.left = 0;
        switch_scene(w, KEY_MENU);
    }
    sfSprite_setTextureRect(
        w->c[SETTINGS_AUDIO_BTN].self.sprite._spr,
        w->c[SETTINGS_AUDIO_BTN].self.sprite._rect
    );
    sfSprite_setTextureRect(
        w->c[SETTINGS_VIDEO_BTN].self.sprite._spr,
        w->c[SETTINGS_VIDEO_BTN].self.sprite._rect
    );
    sfSprite_setTextureRect(
        w->c[SETTINGS_KEY_BTN].self.sprite._spr,
        w->c[SETTINGS_KEY_BTN].self.sprite._rect
    );
}

void on_click_settings_button(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    if (c->id == SETTINGS_BACK_BTN)
        switch_scene(w, pipe_pop(STR("previous_scene")));

    if (c->id == SETTINGS_AUDIO_BTN) {
        c->self.sprite._rect.left = c->self.sprite._rect.width * 2;
        w->c[SETTINGS_KEY_BTN].self.sprite._rect.left = 0;
        w->c[SETTINGS_VIDEO_BTN].self.sprite._rect.left = 0;
        switch_scene(w, AUDIO_MENU);
    }
    if (c->id == SETTINGS_VIDEO_BTN) {
        c->self.sprite._rect.left = c->self.sprite._rect.width * 2;
        w->c[SETTINGS_AUDIO_BTN].self.sprite._rect.left = 0;
        w->c[SETTINGS_KEY_BTN].self.sprite._rect.left = 0;
        switch_scene(w, VIDEO_MENU);
    }
    click_settings_button_bis(w, c, e);
}
