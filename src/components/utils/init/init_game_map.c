/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init game map
*/

#include "my_json.h"
#include "my_str.h"

#include "myrpg/components/defs.h"

void init_game_map(json_elem_t *j, component_t *c)
{
    c->self.map._spr = sfSprite_create();
    c->self.map._clock = sfClock_create();
    str_t *texture = json_get_string(j, 1, "texture");
    str_t *alpha = json_get_string(j, 1, "alpha");

    if (!texture || !alpha || !c->self.map._spr || !c->self.map._clock)
        return;
    c->self.map._tex = sfTexture_createFromFile(str_tocstr(texture), NULL);
    sfSprite_setTexture(c->self.map._spr, c->self.map._tex, sfFalse);
    init_sprite_rect(j, c);
    init_component_bounds(c, j);
    sfSprite_setPosition(
        c->self.map._spr, (sfVector2f){c->bounds.left, c->bounds.top}
    );
    c->self.map._alpha = sfImage_createFromFile(str_tocstr(alpha));
}
