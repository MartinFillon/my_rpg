/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** click_video
*/

#include "myrpg/components/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

static void window_settings(win_t *w, component_t *c)
{
    if (c->id == SETTINGS_VIDEO_FULLSCREEN) {
        c->self.sprite._rect.left = c->self.sprite._rect.width;
        sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
        w->c[SETTINGS_VIDEO_WINDOWED].self.sprite._rect.left = 0;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_WINDOWED].self.sprite._spr,
            w->c[SETTINGS_VIDEO_WINDOWED].self.sprite._rect
        );
        w->settings.fullscreen = sfTrue;
    }
    if (c->id == SETTINGS_VIDEO_WINDOWED) {
        c->self.sprite._rect.left = c->self.sprite._rect.width;
        sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
        w->c[SETTINGS_VIDEO_FULLSCREEN].self.sprite._rect.left = 0;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_FULLSCREEN].self.sprite._spr,
            w->c[SETTINGS_VIDEO_FULLSCREEN].self.sprite._rect
        );
        w->settings.fullscreen = sfFalse;
    }
}

static void thirty_fps(win_t *w, component_t *c)
{
    if (c->id == SETTINGS_VIDEO_30_FPS) {
        c->self.sprite._rect.left = c->self.sprite._rect.width;
        sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
        w->c[SETTINGS_VIDEO_60_FPS].self.sprite._rect.left = 0;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_60_FPS].self.sprite._spr,
            w->c[SETTINGS_VIDEO_60_FPS].self.sprite._rect
        );
        w->c[SETTINGS_VIDEO_144_FPS].self.sprite._rect.left = 0;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_144_FPS].self.sprite._spr,
            w->c[SETTINGS_VIDEO_144_FPS].self.sprite._rect
        );
        w->settings.fps = 30;
    }
}

static void sixty_fps(win_t *w, component_t *c)
{
    if (c->id == SETTINGS_VIDEO_60_FPS) {
        c->self.sprite._rect.left = c->self.sprite._rect.width;
        sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
        w->c[SETTINGS_VIDEO_30_FPS].self.sprite._rect.left = 0;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_30_FPS].self.sprite._spr,
            w->c[SETTINGS_VIDEO_30_FPS].self.sprite._rect
        );
        w->c[SETTINGS_VIDEO_144_FPS].self.sprite._rect.left = 0;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_144_FPS].self.sprite._spr,
            w->c[SETTINGS_VIDEO_144_FPS].self.sprite._rect
        );
        w->settings.fps = 60;
    }
}

static void fps_settings(win_t *w, component_t *c)
{
    thirty_fps(w, c);
    sixty_fps(w, c);
    if (c->id == SETTINGS_VIDEO_144_FPS) {
        c->self.sprite._rect.left = c->self.sprite._rect.width;
        sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
        w->c[SETTINGS_VIDEO_30_FPS].self.sprite._rect.left = 0;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_30_FPS].self.sprite._spr,
            w->c[SETTINGS_VIDEO_30_FPS].self.sprite._rect
        );
        w->c[SETTINGS_VIDEO_60_FPS].self.sprite._rect.left = 0;
        sfSprite_setTextureRect(
            w->c[SETTINGS_VIDEO_60_FPS].self.sprite._spr,
            w->c[SETTINGS_VIDEO_60_FPS].self.sprite._rect
        );
        w->settings.fps = 144;
    }
}

void on_click_settings_video_button(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    window_settings(w, c);
    fps_settings(w, c);
    apply_settings(w);
}
