/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** init_quests
*/

#include "my_json.h"
#include "my_stdio.h"
#include "my_str.h"
#include "my_vec.h"

#include "myrpg/components/defs.h"
#include "myrpg/components/types.h"

sprite_t init_quest_sprite(json_elem_t *j)
{
    sprite_t bubble = {0};
    sfVector2f pos = {0};

    bubble._tex = sfTexture_createFromFile(
        str_tocstr(json_get_string(j, 1, "texture")), NULL
    );
    bubble._spr = sfSprite_create();
    sfSprite_setTexture(bubble._spr, bubble._tex, sfTrue);
    bubble._rect = (sfIntRect){
        json_get_number(j, 2, "rect", "left"),
        json_get_number(j, 2, "rect", "top"),
        json_get_number(j, 2, "rect", "width"),
        json_get_number(j, 2, "rect", "height"),
    };
    sfSprite_setTextureRect(bubble._spr, bubble._rect);
    pos.x = json_get_number(j, 2, "bounds", "left");
    pos.y = json_get_number(j, 2, "bounds", "top");
    sfSprite_setPosition(bubble._spr, pos);
    return bubble;
}

text_t init_quest_text(json_elem_t *j)
{
    text_t text = {0};
    sfVector2f pos = {0};
    double color = json_get_number(j, 1, "color");

    text._font =
        sfFont_createFromFile(str_tocstr(json_get_string(j, 1, "font")));
    text._txt = sfText_create();
    sfText_setColor(text._txt, sfColor_fromInteger(color));
    sfText_setFont(text._txt, text._font);
    sfText_setString(text._txt, str_tocstr(json_get_string(j, 1, "text")));
    sfText_setCharacterSize(
        text._txt, json_get_number(j, 2, "bounds", "height")
    );
    pos.x = json_get_number(j, 2, "bounds", "left");
    pos.y = json_get_number(j, 2, "bounds", "top");
    sfText_setPosition(text._txt, pos);
    return text;
}

quest_t init_quest(str_t *b_file, str_t *v_file, str_t *t_file, str_t *d_file)
{
    quest_t quest = {0};
    json_elem_t *bubble = json_from_file(str_tocstr(b_file));
    json_elem_t *validate = json_from_file(str_tocstr(v_file));
    json_elem_t *text = json_from_file(str_tocstr(t_file));
    json_elem_t *dynamic_content = json_from_file(str_tocstr(d_file));

    quest.quest_box = init_quest_sprite(bubble);
    quest.quest_complete = init_quest_sprite(validate);
    quest.quest_text = init_quest_text(text);
    quest.quest_content =
        (dynamic_content) ? init_quest_text(dynamic_content) : (text_t){0};
    json_free(bubble);
    json_free(validate);
    json_free(text);
    if (dynamic_content)
        json_free(dynamic_content);
    return quest;
}

void init_quests(json_elem_t *j, component_t *c)
{
    vec_json_t *bubbles = json_get_array(j, 1, "bubbles");
    vec_json_t *validate = json_get_array(j, 1, "validate");
    vec_json_t *texts = json_get_array(j, 1, "texts");
    vec_json_t *dynamic_contents = json_get_array(j, 1, "dynamic_content");
    quest_t tmp;

    c->self.quests = vec_create(bubbles->size, sizeof(quest_t));
    for (size_t i = 0; i < bubbles->size; i++) {
        tmp = init_quest(
            bubbles->data[i]->value.string, validate->data[i]->value.string,
            texts->data[i]->value.string,
            dynamic_contents->data[i]->value.string
        );
        vec_pushback(&c->self.quests, &tmp);
    }
}
