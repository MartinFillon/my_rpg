/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** draw_quests
*/

#include "my_stdlib.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

static void render_text(win_t *w, vec_quest_t *quests, size_t i)
{
    if (i <= w->c[MAIN_CHARACTER].self.character.quest - 1) {
        quests->data[i].quest_box._rect.left =
            quests->data[i].quest_box._rect.width;
        sfSprite_setTextureRect(
            quests->data[i].quest_box._spr, quests->data[i].quest_box._rect
        );
        sfRenderWindow_drawText(w->self, quests->data[i].quest_text._txt, NULL);
        if (quests->data[i].quest_content._txt)
            sfRenderWindow_drawText(
                w->self, quests->data[i].quest_content._txt, NULL
            );
    }
}

static void update_morty_count(win_t *w, vec_quest_t *quests, size_t i)
{
    sfText_setString(
        quests->data[i].quest_content._txt,
        my_itoa(w->c[MAIN_CHARACTER].self.character.kills)
    );
    if (w->c[MAIN_CHARACTER].self.character.kills == 500) {
        w->c[MAIN_CHARACTER].self.character.quest += 1;
    }
}

void draw_quests(win_t *w, component_t *c)
{
    vec_quest_t *quests = c->self.quests;

    update_morty_count(w, quests, 1);
    for (size_t i = 0; i < quests->size; i++) {
        if (i <= w->c[MAIN_CHARACTER].self.character.quest - 1) {
            quests->data[i].quest_box._rect.left = 0;
            sfSprite_setTextureRect(
                quests->data[i].quest_box._spr, quests->data[i].quest_box._rect
            );
        }
        sfRenderWindow_drawSprite(
            w->self, quests->data[i].quest_box._spr, NULL
        );
        render_text(w, quests, i);
        if (i < w->c[MAIN_CHARACTER].self.character.quest - 1)
            sfRenderWindow_drawSprite(
                w->self, quests->data[i].quest_complete._spr, NULL
            );
    }
}
