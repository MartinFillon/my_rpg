/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** window
*/

#include "my_json.h"
#include "my_map.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "myrpg/window.h"
#include "myrpg/scenes/scene_ids.h"

static const sfVector2f WINDOW_SIZE = {1920, 1080};

static sfVideoMode get_mode(win_t *w)
{
    if (w->settings.fullscreen)
        return sfVideoMode_getFullscreenModes(NULL)[0];
    else
        return (sfVideoMode){
            WINDOW_SIZE.x,
            WINDOW_SIZE.y,
            json_get_number(w->config, 1, "bpp"),
        };
}

static void set_view_and_resize(win_t *w)
{
    w->_view = sfView_create();
    sfView_reset(w->_view, (sfFloatRect){0, 0, WINDOW_SIZE.x, WINDOW_SIZE.y});
    sfRenderWindow_setView(w->self, w->_view);

    sfVector2u size = {
        json_get_number(w->config, 1, "width"),
        json_get_number(w->config, 1, "height"),
    };
    sfRenderWindow_setSize(w->self, size);
    w->size = size;
}

win_t *init_window(char const *config_file)
{
    win_t *w = malloc(sizeof(win_t));

    if (!w || !(w->config = json_from_file(config_file)))
        return NULL;
    init_settings(w);
    sfVideoMode mode = get_mode(w);
    sfInt32 style = w->settings.fullscreen ? sfFullscreen : sfResize | sfClose;
    char *title = str_tocstr(json_get_string(w->config, 1, "title"));
    char *font = str_tocstr(json_get_string(w->config, 1, "font"));
    w->self = sfRenderWindow_create(mode, title, style, NULL);
    w->clock = sfClock_create();
    w->font = sfFont_createFromFile(font);
    w->current_scene = MAIN_MENU;
    w->stop_propagation = sfFalse;
    set_view_and_resize(w);
    return w;
}

void win_destroy(win_t *w)
{
    update_json(w);
    sfClock_destroy(w->clock);
    sfRenderWindow_destroy(w->self);
    sfView_destroy(w->_view);
    sfFont_destroy(w->font);
    json_write_file(w->config, "conf/window.json");
    json_free(w->config);
    free(w);
}

void win_resize(win_t *w, sfEvent *e)
{
    w->size.x = e->size.width;
    w->size.y = e->size.height;
}
