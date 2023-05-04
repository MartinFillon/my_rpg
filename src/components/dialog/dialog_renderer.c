/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** dialog_renderer
*/

#include "my_cstr.h"
#include "my_json.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

#include "myrpg/components/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

void init_dialog(json_elem_t *json, component_t *c)
{
    str_t *font = json_get_string(json, 1, "font");

    init_component_bounds(c, json);

    c->self.dialog._clock = sfClock_create();
    c->self.text._txt = sfText_create();
    c->self.text._font = sfFont_createFromFile(str_tocstr(font));
    c->self.dialog._speed = json_get_number(json, 1, "speed");
    sfText_setFont(c->self.text._txt, c->self.text._font);
    sfText_setCharacterSize(
        c->self.text._txt, json_get_number(json, 1, "font_size")
    );
    sfText_setColor(c->self.text._txt, sfBlack);
    sfText_setPosition(
        c->self.text._txt, (sfVector2f){c->bounds.left + 60, c->bounds.top + 15}
    );
    c->self.dialog.interval = (c->self.dialog._speed * 10000);
    c->self.dialog.delay = json_get_number(json, 1, "delay") * 100000;
}

void register_dialog(win_t *w, char const *path, component_t *c)
{
    if (c->show)
        return;
    c->self.dialog.json = json_from_file(path);
    c->self.dialog.dialog = json_get_array(c->self.dialog.json, 1, "dialog");
    c->self.dialog.dialog_idx = 0;
    c->self.dialog.sentence_idx = 0;
    c->self.dialog.sentence = str_dup(json_get_string(
        c->self.dialog.dialog->data[c->self.dialog.sentence_idx], 1, "speaker"
    ));
    c->self.dialog.sentence = *str_nadd(&c->self.dialog.sentence, ": ", 2);
    c->show = sfTrue;
    w->c[DIALOG_BACKGROUND].show = sfTrue;
}

void restart_dialog(win_t *w, component_t *c, vec_json_t *dialog)
{
    free(c->self.dialog.sentence);
    c->self.dialog.dialog_idx++;
    if (c->self.dialog.dialog_idx >= dialog->size) {
        c->show = sfFalse;
        w->c[DIALOG_BACKGROUND].show = sfFalse;
        json_free(c->self.dialog.json);
        return;
    }
    c->self.dialog.sentence = str_dup(
        json_get_string(dialog->data[c->self.dialog.dialog_idx], 1, "speaker")
    );
    c->self.dialog.sentence = *str_nadd(&c->self.dialog.sentence, ": ", 2);
    c->self.dialog.sentence_idx = 0;
    c->self.dialog.interval = c->self.dialog.delay;
    sfClock_restart(c->self.dialog._clock);
    draw_dialog(w, c);
    return;
}

void draw_dialog(win_t *w, component_t *c)
{
    vec_json_t *dialog = c->self.dialog.dialog;
    str_t *text =
        json_get_string(dialog->data[c->self.dialog.dialog_idx], 1, "text");

    if (sfClock_getElapsedTime(c->self.dialog._clock).microseconds <
        c->self.dialog.interval)
        return sfRenderWindow_drawText(w->self, c->self.text._txt, NULL);
    c->self.dialog.interval = (c->self.dialog._speed * 10000);
    if (c->self.dialog.sentence_idx > text->length)
        return restart_dialog(w, c, dialog);
    c->self.dialog.sentence = *str_cadd(
        &c->self.dialog.sentence, text->data[c->self.dialog.sentence_idx]
    );
    c->self.dialog.sentence_idx++;
    sfText_setString(c->self.text._txt, str_tocstr(c->self.dialog.sentence));
    sfRenderWindow_drawText(w->self, c->self.text._txt, NULL);
    sfClock_restart(c->self.dialog._clock);
}

void destroy_dialog(component_t *c)
{
    sfClock_destroy(c->self.dialog._clock);
    sfText_destroy(c->self.text._txt);
    sfFont_destroy(c->self.text._font);
}
