/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** destroy_text
*/

#include "myrpg/components/defs.h"

void destroy_text(component_t *c)
{
    sfText_destroy(c->self.text._txt);
    sfFont_destroy(c->self.text._font);
}
