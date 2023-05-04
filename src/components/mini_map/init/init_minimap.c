/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init minimap
*/

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"
#include "my_json.h"
#include "myrpg/components/component_ids.h"

static const sfFloatRect VIEW_RECT = {
    -300,
    -300,
    1920 + 300 * 2,
    1080 + 300 * 2,
};
static const sfVector2f VIEW_SIZE = {1920 + 300 * 2, 1080 + 300 * 2};
static const sfFloatRect VIEWPORT = {0.01f, 0.01f, 0.18f, 0.24f};
static const sfUint32 BG_COLOR = 0x829A9AFF;

void init_minimap(json_elem_t *j, component_t *c)
{
    mini_map_t *self = &c->self.mini_map;

    self->_view = sfView_createFromRect(VIEW_RECT);
    self->_spr = sfSprite_create();
    self->_tex = sfTexture_createFromFile(
        str_tocstr(json_get_string(j, 1, "texture")), NULL
    );
    self->_bg = sfRectangleShape_create();

    sfView_setViewport(self->_view, VIEWPORT);
    sfSprite_setTexture(self->_spr, self->_tex, sfFalse);
    sfRectangleShape_setSize(self->_bg, VIEW_SIZE);
    sfRectangleShape_setPosition(self->_bg, (sfVector2f){-300, -300});
    sfRectangleShape_setFillColor(self->_bg, sfColor_fromInteger(BG_COLOR));
}
