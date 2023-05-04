/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** destroy_projectile
*/

#include <stdlib.h>

#include "my_vec.h"

#include "myrpg/components/defs.h"

void destroy_projectile(component_t *c)
{
    destroy_sprite(c);
    free(c->self.projectiles.data);
    sfClock_destroy(c->self.projectiles._clock);
}
