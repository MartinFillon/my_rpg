/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** sound
*/

#include "my_json.h"
#include "my_map.h"
#include "my_stdlib.h"
#include "my_stdio.h"
#include "my_str.h"
#include "my_vec.h"

#include "myrpg/systems/types.h"
#include "myrpg/window.h"

static str_t *get_file_name(str_t *file)
{
    str_t *name = NULL;
    vec_str_t *tmp = str_split(file, STR("/"));
    vec_str_t *tmp2 = str_split(VEC_LAST(tmp), STR("."));

    name = str_dup(tmp2->data[0]);

    vec_free(tmp);
    vec_free(tmp2);
    return name;
}

void play_sound(system_t *s, str_t *name)
{
    if (s->self.sound._curr && str_eq(s->self.sound._curr, name) == 0)
        return;
    sfSound_stop(s->self.sound._snd);
    sfSound_setBuffer(s->self.sound._snd, map_get(s->self.sound._map, name));
    sfSound_play(s->self.sound._snd);
    s->self.sound._curr = name;
}

void init_sound(json_elem_t *json, system_t *s)
{
    vec_json_t *files = json_get_array(json, 1, "files");
    str_t *file;
    char *path;

    s->self.sound._snd = sfSound_create();
    s->self.sound._map = map_create(100);
    for (size_t i = 0; i < files->size; i++) {
        path = str_tocstr(files->data[i]->value.string);
        file = get_file_name(files->data[i]->value.string);

        map_set(s->self.sound._map, file, sfSoundBuffer_createFromFile(path));
    }
    s->self.sound._curr = NULL;
}

void destroy_sound(system_t *s)
{
    sfSound_destroy(s->self.sound._snd);
    map_free(s->self.sound._map, (void (*)(void *)) & sfSoundBuffer_destroy);
}
