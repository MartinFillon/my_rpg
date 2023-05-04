/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** on_key
*/

#include "my_stdlib.h"

#include "myrpg/components/types.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

void set_keys(win_t *w)
{
    char key[2] = {0};

    key[1] = '\0';
    key[0] = w->settings.up + 'A';
    sfText_setString(w->c[SETTINGS_KEYS_UP_KEY].self.text._txt, key);
    key[0] = w->settings.down + 'A';
    sfText_setString(w->c[SETTINGS_KEYS_DOWN_KEY].self.text._txt, key);
    key[0] = w->settings.left + 'A';
    sfText_setString(w->c[SETTINGS_KEYS_LEFT_KEY].self.text._txt, key);
    key[0] = w->settings.right + 'A';
    sfText_setString(w->c[SETTINGS_KEYS_RIGHT_KEY].self.text._txt, key);
    key[0] = w->settings.interact + 'A';
    sfText_setString(w->c[SETTINGS_KEYS_INTERACT_KEY].self.text._txt, key);
}

void on_key_keymaps(win_t *w, component_t *c, sfEvent *e)
{
    if (c->self.sprite._rect.left == c->self.sprite._rect.width ||
        my_isalpha('A' + e->key.code) == 0)
        return;
    if (c->id == SETTINGS_KEYS_UP_BOX)
        w->settings.up = e->key.code;
    if (c->id == SETTINGS_KEYS_DOWN_BOX)
        w->settings.down = e->key.code;
    if (c->id == SETTINGS_KEYS_LEFT_BOX)
        w->settings.left = e->key.code;
    if (c->id == SETTINGS_KEYS_RIGHT_BOX)
        w->settings.right = e->key.code;
    if (c->id == SETTINGS_KEYS_INTERACT_BOX)
        w->settings.interact = e->key.code;
    c->self.sprite._rect.left = c->self.sprite._rect.width;
    sfSprite_setTextureRect(c->self.sprite._spr, c->self.sprite._rect);
    apply_settings(w);
}
