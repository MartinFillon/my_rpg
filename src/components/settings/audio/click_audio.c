/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** click_audio
*/

#include "my_stdlib.h"

#include "myrpg/components/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

static void sound_buttons(win_t *w, component_t *c)
{
    component_t *sound = &w->c[SETTINGS_AUDIO_SOUND];
    char const *tmp = sfText_getString(sound->self.text._txt);
    long value = my_atoi(tmp);

    if (c->id == SETTINGS_AUDIO_MINUS_SOUND) {
        if (value > 0)
            value--;
    }
    if (c->id == SETTINGS_AUDIO_PLUS_SOUND) {
        if (value < 100)
            value++;
    }
    sfText_setString(sound->self.text._txt, my_itoa(value));
    w->settings.sound_vol = value;
}

static void music_buttons(win_t *w, component_t *c)
{
    component_t *music = &w->c[SETTINGS_AUDIO_MUSIC];
    char const *tmp = sfText_getString(music->self.text._txt);
    long value = my_atoi(tmp);

    if (c->id == SETTINGS_AUDIO_MINUS_MUSIC) {
        if (value > 0)
            value--;
    }
    if (c->id == SETTINGS_AUDIO_PLUS_MUSIC) {
        if (value < 100)
            value++;
    }
    sfText_setString(music->self.text._txt, my_itoa(value));
    w->settings.music_vol = value;
}

void on_click_settings_audio_button(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    c->self.sprite._rect.left = c->self.sprite._rect.width;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
    sound_buttons(w, c);
    music_buttons(w, c);
    apply_settings(w);
}
