/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** save
*/

#include <fcntl.h>
#include <unistd.h>

#include "my_json.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "myrpg/components/types.h"
#include "myrpg/systems/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/systems/system_ids.h"

static const char SAVE_DEFAULT[] =
    "{\"slots\":[{\"stats\":{\"hp\":40,\"atk\":20,\"def\":20},\"deaths\":0,"
    "\"kills\":0,\"coins\":0,\"quest\":1},{\"stats\":{\"hp\":40,\"atk\":20,"
    "\"def\":20},\"deaths\":0,\"kills\":0,\"coins\":0,\"quest\":1},{\"stats\":{"
    "\"hp\":40,\"atk\":20,\"def\":20},\"deaths\":0,\"kills\":0,\"coins\":0,"
    "\"quest\":1}]}";

// clang-format off
void init_save(json_elem_t *j, system_t *s)
{
    str_t *file = json_get_string(j, 1, "save");
    if (file == NULL)
        return;
    str_t *compressed = read_file(str_tocstr(file));
    str_t *buff = NULL;
    if (compressed != NULL) {
        buff = decompress_string(compressed);
    } else {
        buff = str_screate(1024);
        str_add(&buff, SAVE_DEFAULT);
    }
    json_elem_t *json = json_parse(buff);
    json = (json == NULL) ?
        json_parse(*str_add(str_clear(&buff), SAVE_DEFAULT)) : json;
    s->self.save._clock = sfClock_create();
    s->self.save.json = json;
    s->self.save.slot_idx = -1;
    s->self.save.dest = my_strdup(str_tocstr(file));
    free(buff);
}
// clang-format on

static void write_save_to_file(system_t *s)
{
    str_t *buff = json_stringify(s->self.save.json);
    str_t *compressed = compress_string(buff);
    int fd = open(s->self.save.dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        my_dprintf(2, "Failed to save game\n");
        return;
    }
    str_dprint(fd, compressed);
    close(fd);
    free(compressed);
}

void destroy_save(system_t *s)
{
    write_save_to_file(s);
    free(s->self.save.dest);
    sfClock_destroy(s->self.save._clock);
    json_free(s->self.save.json);
}

void save_game_state(win_t *w, system_t *s)
{
    int idx = w->s[SAVE].self.save.slot_idx;
    if (idx == -1)
        return;

    if (sfTime_asSeconds(sfClock_getElapsedTime(s->self.save._clock)) < 2)
        return;
    sfClock_restart(s->self.save._clock);
    character_t *c = &w->c[MAIN_CHARACTER].self.character;
    vec_json_t *slots = json_get_array(w->s[SAVE].self.save.json, 1, "slots");
    json_get(slots->data[idx], 1, "deaths")->value.number = c->deaths;
    json_get(slots->data[idx], 1, "kills")->value.number = c->kills;
    json_get(slots->data[idx], 1, "coins")->value.number = c->coins;
    json_get(slots->data[idx], 1, "quest")->value.number = c->quest;
    json_get(slots->data[idx], 2, "stats", "def")->value.number = c->stats.def;
    json_get(slots->data[idx], 2, "stats", "hp")->value.number = c->stats.hp;
    json_get(slots->data[idx], 2, "stats", "atk")->value.number = c->stats.atk;
    write_save_to_file(s);
}
