/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** music
*/

#include "my_str.h"
#include <stdio.h>

#include "myrpg/systems/defs.h"
#include "myrpg/window.h"

void init_music(json_elem_t *j, system_t *s)
{
    str_t *file = json_get_string(j, 1, "file");
    s->self.music._msc = sfMusic_createFromFile(str_tocstr(file));

    if (!s->self.music._msc)
        return;
    sfMusic_setLoop(s->self.music._msc, sfTrue);
    sfMusic_setVolume(s->self.music._msc, 100);
    sfMusic_play(s->self.music._msc);
}

void destroy_music(system_t *s)
{
    sfMusic_destroy(s->self.music._msc);
}
