/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-martin.fillon
** File description:
** systems
*/

#ifndef SYSTEM_LIST_H_
    #define SYSTEM_LIST_H_

    #include "myrpg/systems/system_ids.h"


static const system_t SYSTEMS[] = {
    {
        .config_file = "conf/sound.json",
        .name = "sound",
        .id = SOUND,
        .active = sfTrue,
        .init = &init_sound,
        .run = NULL,
        .destroy = &destroy_sound,
    },
    {
        .config_file = "conf/music.json",
        .name = "music",
        .id = MUSIC,
        .active = sfTrue,
        .init = &init_music,
        .run = NULL,
        .destroy = &destroy_music,
    },
    {
        .config_file = "conf/save.json",
        .name = "save",
        .id = SAVE,
        .active = sfTrue,
        .init = &init_save,
        .run = &save_game_state,
        .destroy = &destroy_save,
    },
};


#endif /* !SYSTEM_LIST_H_ */
