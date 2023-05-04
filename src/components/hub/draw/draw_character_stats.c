/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** draw character stats
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/component_ids.h"

static const int WIDTH = 224;
static const int MAX_LIFE = 100;

void draw_character_stats(win_t *w, component_t *c)
{
    character_t *chr = &w->c[MAIN_CHARACTER].self.character;

    double value = 0.0;
    switch (c->id) {
        case GAME_MENU_BAR_ATK: value = chr->stats.atk; break;
        case GAME_MENU_BAR_HP: value = chr->stats.hp; break;
        case GAME_MENU_BAR_SHIELD: value = chr->stats.def; break;
    }

    c->self.sprite._rect.width = (value * WIDTH) / MAX_LIFE;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
    draw_sprite(w, c);
}
