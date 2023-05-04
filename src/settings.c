/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** settings
*/

#include "my_json.h"
#include "my_stdio.h"
#include "my_stdlib.h"

#include "myrpg/components/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/systems/system_ids.h"

void init_settings(win_t *w)
{
    w->settings.sound_vol =
        json_get_number(w->config, 2, "settings", "sound_volume");
    w->settings.music_vol =
        json_get_number(w->config, 2, "settings", "music_volume");
    w->settings.fps = json_get_number(w->config, 2, "settings", "fps");
    w->settings.up = json_get_number(w->config, 2, "settings", "up");
    w->settings.down = json_get_number(w->config, 2, "settings", "down");
    w->settings.left = json_get_number(w->config, 2, "settings", "left");
    w->settings.right = json_get_number(w->config, 2, "settings", "right");
    w->settings.interact =
        json_get_number(w->config, 2, "settings", "interact");
    w->settings.fullscreen =
        json_get_bool(w->config, 2, "settings", "fullscreen");
}

void update_json(win_t *w)
{
    json_get(w->config, 2, "settings", "fullscreen")->value.boolean =
        w->settings.fullscreen;
    json_get(w->config, 2, "settings", "sound_volume")->value.number =
        w->settings.sound_vol;
    json_get(w->config, 2, "settings", "music_volume")->value.number =
        w->settings.music_vol;
    json_get(w->config, 2, "settings", "fps")->value.number = w->settings.fps;
    json_get(w->config, 2, "settings", "up")->value.number = w->settings.up;
    json_get(w->config, 2, "settings", "down")->value.number = w->settings.down;
    json_get(w->config, 2, "settings", "left")->value.number = w->settings.left;
    json_get(w->config, 2, "settings", "right")->value.number =
        w->settings.right;
    json_get(w->config, 2, "settings", "interact")->value.number =
        w->settings.interact;
}
