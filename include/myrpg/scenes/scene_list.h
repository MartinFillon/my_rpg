/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** scenes manager
*/

#ifndef SCENE_LIST_
    #define SCENE_LIST_

    #include "myrpg/components/types.h"

    #include "myrpg/components/component_ids.h"
    #include "myrpg/scenes/scene_ids.h"

typedef struct {
    int id;
    const int *components;
} scene_list_t;

static const scene_list_t SCENE_LIST[] = {
    {
        .id = MAIN_MENU,
        .components =
            (int[]){
                MAIN_MENU_BACKGROUND,
                MAIN_MENU_PLAY_BTN,
                MAIN_MENU_QUIT_BTN,
                MAIN_MENU_HELP_BTN,
                MAIN_MENU_SETTINGS_BTN,
                MAIN_MENU_PORTAL,
                -1,
            },
    },
    {
        .id = SAVE_MENU,
        .components =
            (int[]){
                SAVE_MENU_BACKGROUND,
                SAVE_MENU_SLOT_1,
                SAVE_MENU_SLOT_2,
                SAVE_MENU_SLOT_3,
                SAVE_MENU_LOAD_1,
                SAVE_MENU_LOAD_2,
                SAVE_MENU_LOAD_3,
                SAVE_MENU_BACK_BTN,
                -1,
            },
    },
    {
        .id = SELECT_SKIN,
        .components =
            (int[]){
                SELECT_SKIN_BACKGROUND,
                SELECT_SKIN_SELECT_BTN,
                SELECT_SKIN_PREV_BTN,
                SELECT_SKIN_NEXT_BTN,
                SELECT_SKIN_SKINS,
                SELECT_SKIN_BACK_BTN,
                -1,
            },
    },
    {
        .id = SETTINGS,
        .components =
            (int[]){
                SETTINGS_BACKGROUND,
                SETTINGS_AUDIO_BTN,
                SETTINGS_VIDEO_BTN,
                SETTINGS_KEY_BTN,
                SETTINGS_BACK_BTN,
                -1,
            },
    },
    {
        .id = HUB,
        .components =
            (int[]){
                HUB_MAP,
                HUB_PORTAL,
                HUB_BETH,
                HUB_JERRY,
                HUB_BIRDMAN,
                HUB_SUMMER,
                HUB_PORTAL_GUN,
                MAIN_CHARACTER,
                HUB_VIGNETTE,
                GAME_MENU_ICON,
                GAME_SETTINGS_ICON,
                -1,
            },
    },
    {
        .id = GAME_MENU,
        .components =
            (int[]){
                GAME_MENU_BACKGROUND,
                GAME_MENU_INVENTORY_BTN,
                GAME_MENU_QUEST_BTN,
                GAME_MENU_BESTIARY_BTN,
                GAME_MENU_SKIN_BTN,
                GAME_MENU_BACK_BTN,
                GAME_MENU_QUIT_BTN,
                -1,
            },
    },
    {
        .id = GAME_MENU_INVENTORY,
        .components =
            (int[]){
                GAME_MENU_BACKGROUND,
                GAME_MENU_INVENTORY_BTN,
                GAME_MENU_QUEST_BTN,
                GAME_MENU_BESTIARY_BTN,
                GAME_MENU_SKIN_BTN,
                GAME_MENU_BACK_BTN,
                GAME_MENU_QUIT_BTN,
                GAME_MENU_LEFT,
                GAME_MENU_STAT,
                GAME_MENU_SKIN,
                GAME_MENU_BAR_ATK,
                GAME_MENU_BAR_HP,
                GAME_MENU_BAR_SHIELD,
                GAME_MENU_BAR_DRUNK,
                GAME_MENU_INVENTORY_BOX_1,
                GAME_MENU_INVENTORY_BOX_2,
                GAME_MENU_INVENTORY_BOX_3,
                GAME_MENU_INVENTORY_BOX_4,
                GAME_MENU_INVENTORY_BOX_5,
                GAME_MENU_INVENTORY_BOX_6,
                GAME_MENU_INVENTORY_BOX_7,
                -1,
            },
    },
    {
        .id = IN_GAME_MENU_QUEST,
        .components =
            (int[]){
                GAME_MENU_BACKGROUND,
                GAME_MENU_INVENTORY_BTN,
                GAME_MENU_QUEST_BTN,
                GAME_MENU_BESTIARY_BTN,
                GAME_MENU_SKIN_BTN,
                GAME_MENU_BACK_BTN,
                GAME_MENU_QUIT_BTN,
                QUEST_ICON_SWORD,
                QUESTS,
                -1,
            },
    },
    {
        .id = IN_GAME_MENU_SKIN,
        .components =
            (int[]){
                SELECT_SKIN_BACKGROUND,
                IN_GAME_SKIN_SELECT_BTN,
                SELECT_SKIN_PREV_BTN,
                SELECT_SKIN_NEXT_BTN,
                SELECT_SKIN_SKINS,
                IN_GAME_SKIN_BACK_BTN,
                -1,
            },
    },
    {
        .id = IN_GAME_MENU_BESTIARY,
        .components =
            (int[]){
                GAME_MENU_BACKGROUND, GAME_MENU_INVENTORY_BTN,
                GAME_MENU_QUEST_BTN,  GAME_MENU_BESTIARY_BTN,
                GAME_MENU_SKIN_BTN,   GAME_MENU_BACK_BTN,
                GAME_MENU_QUIT_BTN,   BESTIARY_BACKGROUND,
                BESTIARY_1,           BESTIARY_2,
                BESTIARY_3,           BESTIARY_4,
                BESTIARY_5,           BESTIARY_6,
                BESTIARY_7,           BESTIARY_8,
                BESTIARY_9,           BESTIARY_10,
                BESTIARY_11,          BESTIARY_12,
                BESTIARY_13,          BESTIARY_14,
                BESTIARY_15,          BESTIARY_MOON,
                BESTIARY_SUN,         BESTIARY_MECHA,
                BESTIARY_RABBIT,      BESTIARY_MOTION,
                BESTIARY_BOSS,        -1,
            },
    },
    {
        .id = SHOP,
        .components =
            (int[]){
                SHOP_BACKGROUND,
                SHOP_BETH,
                SHOP_BUY_BTN,
                SHOP_BOOST_ATCK1,
                SHOP_BOOST_ATCK2,
                SHOP_BOOST_HP1,
                SHOP_BOOST_HP2,
                SHOP_BOOST_SHIELD1,
                SHOP_BOOST_SHIELD2,
                SHOP_BACK_BTN,
                SHOP_MONEY_COUNTER,
                -1,
            },
    },
    {
        .id = AUDIO_MENU,
        .components =
            (int[]){
                SETTINGS_BACKGROUND,
                SETTINGS_AUDIO_BTN,
                SETTINGS_VIDEO_BTN,
                SETTINGS_KEY_BTN,
                SETTINGS_BACK_BTN,
                SETTINGS_AUDIO,
                SETTINGS_AUDIO_MUSIC,
                SETTINGS_AUDIO_SOUND,
                SETTINGS_AUDIO_MINUS_MUSIC,
                SETTINGS_AUDIO_PLUS_MUSIC,
                SETTINGS_AUDIO_MINUS_SOUND,
                SETTINGS_AUDIO_PLUS_SOUND,
                -1,
            },
    },
    {
        .id = VIDEO_MENU,
        .components =
            (int[]){
                SETTINGS_BACKGROUND,
                SETTINGS_AUDIO_BTN,
                SETTINGS_VIDEO_BTN,
                SETTINGS_KEY_BTN,
                SETTINGS_BACK_BTN,
                SETTINGS_VIDEO,
                SETTINGS_VIDEO_FULLSCREEN,
                SETTINGS_VIDEO_WINDOWED,
                SETTINGS_VIDEO_30_FPS,
                SETTINGS_VIDEO_60_FPS,
                SETTINGS_VIDEO_144_FPS,
                -1,
            },
    },
    {
        .id = KEY_MENU,
        .components =
            (int[]){
                SETTINGS_BACKGROUND,
                SETTINGS_AUDIO_BTN,
                SETTINGS_VIDEO_BTN,
                SETTINGS_KEY_BTN,
                SETTINGS_BACK_BTN,
                SETTINGS_KEYS_UP_BOX,
                SETTINGS_KEYS_UP_TEXT,
                SETTINGS_KEYS_UP_KEY,
                SETTINGS_KEYS_DOWN_BOX,
                SETTINGS_KEYS_DOWN_TEXT,
                SETTINGS_KEYS_DOWN_KEY,
                SETTINGS_KEYS_LEFT_BOX,
                SETTINGS_KEYS_LEFT_TEXT,
                SETTINGS_KEYS_LEFT_KEY,
                SETTINGS_KEYS_RIGHT_BOX,
                SETTINGS_KEYS_RIGHT_TEXT,
                SETTINGS_KEYS_RIGHT_KEY,
                SETTINGS_KEYS_INTERACT_BOX,
                SETTINGS_KEYS_INTERACT_TEXT,
                SETTINGS_KEYS_INTERACT_KEY,
                -1,
            },
    },
    {
        .id = SELECT_MAP,
        .components =
            (int[]){
                SELECT_MAP_BACKGROUND,
                SELECT_MAP_BACK,
                SELECT_MAP_PLANET_1,
                SELECT_MAP_PLANET_2,
                SELECT_MAP_PLANET_3,
                -1,
            },
    },
    {
        .id = PROCEDURAL_MAP,
        .components =
            (int[]){
                GAME_PROCEDURAL_MAP,
                MAIN_CHARACTER,
                GAME_PROCEDURAL_MAP_ENEMYS,
                GAME_MENU_ICON,
                GAME_SETTINGS_ICON,
                -1,
            },
    },
    {
        .id = DEAD,
        .components =
            (int[]){
                DEATH_ANIMATION,
                -1,
            },
    },
    {
        .id = HELP,
        .components =
            (int[]){
                HELP_BACKGROUND,
                HELP_BACK,
                -1,
            },
    },
    {
        .id = NONE,
        .components =
            (int[]){
                -1,
            },
    },
};

#endif /* !SCENE_LIST_ */
