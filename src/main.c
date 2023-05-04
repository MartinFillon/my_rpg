/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** main
*/

#include <time.h>

#include "my_json.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "myrpg/events.h"
#include "myrpg/pipe.h"
#include "myrpg/systems/defs.h"
#include "myrpg/window.h"
#include "myrpg/components/component_ids.h"

static int check_env(char const *const *env)
{
    if (env == NULL)
        return 1;

    while (*env) {
        if (my_strncmp(*env, "DISPLAY=", 8) == 0)
            return 0;
        env++;
    }

    return 1;
}

static int start_game(void)
{
    win_t *window = init_window("conf/window.json");

    if (window == NULL)
        return 84;
    init_components(window);
    init_systems(window);
    apply_settings(window);
    update_save_menu_loads(window);
    while (sfRenderWindow_isOpen(window->self)) {
        handle_events(window);
        sfRenderWindow_clear(window->self, sfWhite);
        draw_components(window);
        run_systems(window);
        sfRenderWindow_display(window->self);
    }
    destroy_components(window);
    destroy_systems(window);
    win_destroy(window);
    pipe_free();
    return 0;
}

int main(int UNUSED ac, char UNUSED **av, char const *const *env)
{
    if (check_env(env))
        return 84;
    srand(time(NULL));

    return start_game();
}
