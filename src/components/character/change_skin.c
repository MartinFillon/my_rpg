/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** change character skin
*/

#include "myrpg/components/defs.h"
#include "myrpg/pipe.h"
#include "myrpg/components/component_ids.h"

void change_skin(win_t *w)
{
    int skin_id = pipe_read(STR("skin_id"));
    pipe_write(STR("skin_id"), skin_id);

    json_elem_t *json = json_from_file(w->c[MAIN_CHARACTER].config_file);
    vec_json_t *skins = json_get_array(json, 1, "skins");
    str_t *texture = json_get_string(json, 1, "texture");

    destroy_anim_sprite(&w->c[MAIN_CHARACTER]);
    str_sadd(str_clear(&texture), skins->data[skin_id]->value.string);
    init_anim_sprite(json, &w->c[MAIN_CHARACTER]);
    json_free(json);
}
