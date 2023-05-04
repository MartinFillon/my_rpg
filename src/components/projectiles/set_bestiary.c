/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** set_bestiary
*/

#include <stddef.h>

#include "myrpg/components/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_list.h"

static void set_rect(win_t *w, size_t i, size_t j, size_t k)
{
    if (w->c[GAME_PROCEDURAL_MAP_ENEMYS].self.enemy._sprs[j]->data[k] ==
        w->c[GAME_PROCEDURAL_MAP_ENEMYS].self.enemy._enemies->data[i]._spr) {
        w->c[BESTIARY_1 + (j * 5) + k].self.sprite._rect.left =
            w->c[BESTIARY_1 + (j * 5) + k].self.sprite._rect.width;
        sfSprite_setTextureRect(
            w->c[BESTIARY_1 + (j * 5) + k].self.sprite._spr,
            w->c[BESTIARY_1 + (j * 5) + k].self.sprite._rect
        );
        return;
    }
}

void set_bestiary(win_t *w, size_t i)
{
    for (size_t j = 0; j < 3; j++) {
        for (size_t k = 0; k < 5; k++) {
            set_rect(w, i, j, k);
        }
    }
}
