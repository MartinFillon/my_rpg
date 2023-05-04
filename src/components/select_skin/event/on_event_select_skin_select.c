/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** on_click_selector
*/

#include "my_json.h"
#include "my_utils.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "myrpg/pipe.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/scenes/scene_ids.h"

static const int SKIN_MAX_WIDTH = 5040;

static void move_skin(win_t *w, component_t *c)
{
    int left = w->c[SELECT_SKIN_SKINS].self.sprite._rect.left;

    switch (c->id) {
        case SELECT_SKIN_NEXT_BTN:
            left += 630;
            break;
        case SELECT_SKIN_PREV_BTN:
            left -= 630;
            break;
    }
    left += (left < 0) ? SKIN_MAX_WIDTH : 0;
    left -= (left >= SKIN_MAX_WIDTH) ? SKIN_MAX_WIDTH : 0;
    w->c[SELECT_SKIN_SKINS].self.sprite._rect.left = left;
    sfSprite_setTextureRect(
        w->c[SELECT_SKIN_SKINS].self.sprite._spr,
        w->c[SELECT_SKIN_SKINS].self.sprite._rect
    );
}

void on_click_select_skin_btn(win_t *w, component_t *c, sfEvent UNUSED *e)
{
    int skin_id = pipe_read(STR("skin_id"));
    skin_id = (skin_id == -1) ? 0 : skin_id;
    skin_id = (c->id == SELECT_SKIN_NEXT_BTN) ? ((skin_id + 1) % 8) : skin_id;
    skin_id = (c->id == SELECT_SKIN_PREV_BTN) ? ((skin_id + 7) % 8) : skin_id;
    pipe_write(STR("skin_id"), skin_id);

    if (c->id == SELECT_SKIN_NEXT_BTN || c->id == SELECT_SKIN_PREV_BTN)
        move_skin(w, c);
    if (c->id == SELECT_SKIN_SELECT_BTN) {
        change_skin(w);
        switch_scene(w, HUB);
    }
    if (c->id == SELECT_SKIN_BACK_BTN) {
        switch_scene(w, SAVE_MENU);
    }
    w->stop_propagation = sfTrue;
}
