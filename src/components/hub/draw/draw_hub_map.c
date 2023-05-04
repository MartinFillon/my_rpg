/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** move
*/

#include "myrpg/components/defs.h"
#include "myrpg/scenes/defs.h"
#include "myrpg/components/component_ids.h"

static const sfUint32 WHITE = 0xFFFFFFFF;
static const int MOVEMENT = 10;
static const sfIntRect VIEWPORT = {0, 0, 1920, 1080};
static const int LOCKED[] = {
    MAIN_CHARACTER, GAME_MENU_ICON, HUB_VIGNETTE, GAME_SETTINGS_ICON, -1,
};
static const sfVector2i DIRS[4] = {
    {0, MOVEMENT},
    {-MOVEMENT, 0},
    {MOVEMENT, 0},
    {0, -MOVEMENT},
};

// clang-format off
static sfBool check_valid_pos(component_t *c, int dir)
{
    sfBool is_x = (dir == 1 || dir == 2);
    sfIntRect plr = {
        -(int)c->bounds.left + VIEWPORT.width / 2 + DIRS[dir].x - 30,
        -(int)c->bounds.top + VIEWPORT.height / 2 + DIRS[dir].y, 60, 70};
    sfVector2i inters[2] = {
        {plr.left, plr.left + plr.width}, {plr.top, plr.top + plr.height}};
    sfVector2i inter = inters[is_x];
    sfVector2i checks[4] = {
        {0, plr.top + plr.height}, {plr.left, 0},
        {plr.left + plr.width, 0}, {0, plr.top}};
    sfVector2i check = checks[dir];

    for (int i = inter.x; i < inter.y; ++i)
        if (sfColor_toInteger(sfImage_getPixel(
                c->self.map._alpha, !is_x ? i : check.x, is_x ? i : check.y
            )) == WHITE)
            return sfTrue;
    return sfFalse;
}

// clang-format on
static void catch_keyboard_evt(win_t *w, component_t *c)
{
    int KEYS[4] = {
        w->settings.down, w->settings.left, w->settings.right, w->settings.up};

    if (sfTime_asSeconds(sfClock_getElapsedTime(c->self.map._clock)) < 0.01)
        return;
    sfClock_restart(c->self.map._clock);
    for (int i = 0; i < 4; ++i) {
        if (!sfKeyboard_isKeyPressed(KEYS[i]) || check_valid_pos(c, i))
            continue;
        set_movement_particle(w, (sfVector2f){-DIRS[i].x, -DIRS[i].y});
        set_movement_animation(&w->c[MAIN_CHARACTER], i + 1);
        move_scene_components(w, LOCKED, (sfVector2f){-DIRS[i].x, -DIRS[i].y});
        move_projectiles(w, (sfVector2f){-DIRS[i].x, -DIRS[i].y});
        break;
    }
}

void draw_hub_map(win_t *w, component_t *c)
{
    catch_keyboard_evt(w, c);
    draw_sprite(w, c);
}
