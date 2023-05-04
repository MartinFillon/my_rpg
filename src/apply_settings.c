/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** apply_settings
*/

#include "my_stdlib.h"

#include "myrpg/components/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/systems/system_ids.h"

static void set_144_fps(win_t *w)
{
    if (w->settings.fps == 144) {
        w->c[SETTINGS_VIDEO_144_FPS].self.sprite._rect.left =
            w->c[SETTINGS_VIDEO_144_FPS].self.sprite._rect.width;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_144_FPS].self.sprite._spr,
            w->c[SETTINGS_VIDEO_144_FPS].self.sprite._rect
        );
    }
}

static void set_fps(win_t *w)
{
    sfRenderWindow_setFramerateLimit(w->self, w->settings.fps);
    if (w->settings.fps == 30) {
        w->c[SETTINGS_VIDEO_30_FPS].self.sprite._rect.left =
            w->c[SETTINGS_VIDEO_30_FPS].self.sprite._rect.width;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_30_FPS].self.sprite._spr,
            w->c[SETTINGS_VIDEO_30_FPS].self.sprite._rect
        );
    }
    if (w->settings.fps == 60) {
        w->c[SETTINGS_VIDEO_60_FPS].self.sprite._rect.left =
            w->c[SETTINGS_VIDEO_60_FPS].self.sprite._rect.width;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_60_FPS].self.sprite._spr,
            w->c[SETTINGS_VIDEO_60_FPS].self.sprite._rect
        );
    }
    set_144_fps(w);
}

static void set_sound(win_t *w)
{
    char *music_vol = my_itoa(w->settings.music_vol);
    char *sound_vol = my_itoa(w->settings.sound_vol);

    if (w->s[SOUND].self.sound._snd) {
        sfText_setString(w->c[SETTINGS_AUDIO_SOUND].self.text._txt, sound_vol);
        sfSound_setVolume(w->s[SOUND].self.sound._snd, w->settings.sound_vol);
    }
    if (w->s[MUSIC].self.music._msc) {
        sfText_setString(w->c[SETTINGS_AUDIO_MUSIC].self.text._txt, music_vol);
        sfMusic_setVolume(w->s[MUSIC].self.music._msc, w->settings.music_vol);
    }
    my_vfree(2, sound_vol, music_vol);
}

static void set_video_settings(win_t *w)
{
    if (w->settings.fullscreen) {
        w->c[SETTINGS_VIDEO_FULLSCREEN].self.sprite._rect.left =
            w->c[SETTINGS_VIDEO_FULLSCREEN].self.sprite._rect.width;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_FULLSCREEN].self.sprite._spr,
            w->c[SETTINGS_VIDEO_FULLSCREEN].self.sprite._rect
        );
    } else {
        w->c[SETTINGS_VIDEO_WINDOWED].self.sprite._rect.left =
            w->c[SETTINGS_VIDEO_WINDOWED].self.sprite._rect.width;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_WINDOWED].self.sprite._spr,
            w->c[SETTINGS_VIDEO_WINDOWED].self.sprite._rect
        );
    }
}

void apply_settings(win_t *w)
{
    set_fps(w);
    set_video_settings(w);
    set_sound(w);
    set_keys(w);
}
