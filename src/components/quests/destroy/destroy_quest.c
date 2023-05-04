/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** destroy_quest
*/

#include "my_stdlib.h"

#include "myrpg/window.h"
#include "myrpg/components/types.h"

static void destroy_vec(quest_t *q)
{
    sfSprite_destroy(q->quest_box._spr);
    sfSprite_destroy(q->quest_complete._spr);
    sfText_destroy(q->quest_text._txt);
    sfText_destroy(q->quest_content._txt);
    sfFont_destroy(q->quest_text._font);
    sfFont_destroy(q->quest_content._font);
    sfTexture_destroy(q->quest_box._tex);
    sfTexture_destroy(q->quest_complete._tex);
}

void destroy_quests(component_t *c)
{
    for (size_t i = 0; i < c->self.quests->size; i++) {
        destroy_vec(&c->self.quests->data[i]);
    }
    free(c->self.quests);
}
