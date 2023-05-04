/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** init_text
*/

#include "my_json.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "myrpg/components/defs.h"

void init_text(json_elem_t *json, component_t *c)
{
    str_t *font = json_get_string(json, 1, "font");
    str_t *str = json_get_string(json, 1, "text");
    double color_json = json_get_number(json, 1, "color");
    sfColor color = sfColor_fromInteger(color_json);

    c->self.text._txt = sfText_create();
    c->self.text._font = sfFont_createFromFile(str_tocstr(font));
    sfText_setFont(c->self.text._txt, c->self.text._font);
    sfText_setString(c->self.text._txt, str_tocstr(str));
    sfText_setColor(c->self.text._txt, color);
    init_component_bounds(c, json);
    sfText_setPosition(
        c->self.text._txt, (sfVector2f){c->bounds.left, c->bounds.top}
    );
    sfText_setCharacterSize(c->self.text._txt, c->bounds.height);
}
