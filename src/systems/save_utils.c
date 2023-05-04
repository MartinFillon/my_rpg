/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** save utils
*/

#include "myrpg/components/types.h"
#include "myrpg/systems/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"
#include "myrpg/systems/system_ids.h"

void update_save_menu_loads(win_t *w)
{
    save_t *s = &w->s[SAVE].self.save;
    vec_json_t *slots = json_get_array(s->json, 1, "slots");
    json_elem_t *slot = NULL;

    for (size_t i = 0; i < slots->size; i++) {
        slot = slots->data[i];
        sprite_t *load = &w->c[SAVE_MENU_LOAD_1 + i].self.sprite;
        load->_rect.left = load->_rect.width *
            MIN((int)json_get_number(slot, 1, "quest") - 1, 5);
        sfSprite_setTextureRect(load->_spr, load->_rect);
    }
}

void load_save(win_t *w, size_t slot_idx)
{
    save_t *s = &w->s[SAVE].self.save;
    character_t *chr = &w->c[MAIN_CHARACTER].self.character;
    json_elem_t *slot = json_get_array(s->json, 1, "slots")->data[slot_idx];

    s->slot_idx = slot_idx;
    chr->stats.hp = json_get_number(slot, 2, "stats", "hp");
    chr->stats.atk = json_get_number(slot, 2, "stats", "atk");
    chr->stats.def = json_get_number(slot, 2, "stats", "def");
    chr->deaths = json_get_number(slot, 1, "deaths");
    chr->kills = json_get_number(slot, 1, "kills");
    chr->coins = json_get_number(slot, 1, "coins");
    chr->quest = json_get_number(slot, 1, "quest");
}
