##
## EPITECH PROJECT, 2023
## my_paint
## File description:
## Makefile
##

CC	=	gcc
RM	=	rm -f

SRC	=	./src/main.c														\
		./src/window.c 														\
		./src/settings.c 													\
		./src/apply_settings.c												\
		\
		./src/pipe/pipe_communicate.c 										\
		\
		./src/file_compression/compress_string.c		 					\
		./src/file_compression/read_n_bits.c		 						\
		./src/file_compression/uncompress_string.c		 					\
		./src/file_compression/write_n_bits.c		 						\
		\
		./src/scenes/switch_scene.c		 									\
		./src/scenes/move_scene_components.c								\
		\
		./src/events/click_middleware.c 									\
		./src/events/hover_middleware.c 									\
		./src/events/leave_middleware.c 									\
		./src/events/release_middleware.c 									\
		./src/events/key_middleware.c 										\
		./src/events/handle_events.c 										\
		./src/events/get_mouse_pos.c										\
		\
		./src/components/components.c 										\
		./src/components/callbacks.c										\
		\
		./src/components/utils/movement/set_movement_animation.c			\
		./src/components/utils/event/stop_propagation.c						\
		./src/components/utils/event/on_event_button.c						\
		./src/components/utils/destroy/destroy_sprite.c						\
		./src/components/utils/destroy/destroy_npc.c						\
		./src/components/utils/destroy/destroy_anim_sprite.c				\
		./src/components/utils/destroy/destroy_game_map.c					\
		./src/components/utils/destroy/destroy_text.c						\
		./src/components/utils/draw/draw_sprite.c							\
		./src/components/utils/draw/draw_text.c								\
		./src/components/utils/init/init_component_bounds.c					\
		./src/components/utils/init/init_sprite.c							\
		./src/components/utils/init/init_sprite_rect.c						\
		./src/components/utils/init/init_game_map.c							\
		./src/components/utils/init/init_anim_sprite.c						\
		./src/components/utils/init/init_text.c								\
		./src/components/utils/init/init_npc.c								\
		./src/components/utils/init/init_stats.c 							\
		./src/components/utils/init/init_character.c 						\
		./src/components/utils/math/component_distance.c					\
		\
		./src/components/mini_map/init/init_minimap.c						\
		./src/components/mini_map/draw/draw_minimap.c						\
		./src/components/mini_map/destroy/destroy_minimap.c					\
		\
		./src/components/main_menu/draw/draw_main_menu_portal.c				\
		./src/components/main_menu/draw/draw_main_menu_button.c				\
		./src/components/main_menu/init/init_main_menu_portal.c				\
		./src/components/main_menu/event/on_custom_main_menu_portal.c		\
		./src/components/main_menu/event/on_click_main_menu_button.c		\
		\
		./src/components/character/event/interact.c 						\
		./src/components/character/event/custom_shoot.c 					\
		./src/components/character/change_skin.c 							\
		\
		./src/components/hub/event/on_custom_hub_portal.c					\
		./src/components/hub/draw/draw_hub_map.c							\
		./src/components/hub/draw/draw_portal.c								\
		./src/components/hub/draw/draw_character_stats.c					\
		./src/components/hub/event/on_event_in_game_menu.c					\
		./src/components/hub/event/on_click_in_game_menu.c					\
		./src/components/hub/event/on_click_shop.c							\
		./src/components/hub/event/on_key_escape_game.c						\
		./src/components/hub/event/on_click_on_quest_btn.c					\
		./src/components/hub/event/reset_in_game_menu.c						\
		./src/components/hub/event/on_key_portal_gun.c						\
		\
		./src/components/procedural_map/perlin_noise.c						\
		./src/components/procedural_map/generate_map.c						\
		./src/components/procedural_map/generate_chunk.c					\
		./src/components/procedural_map/init/init_procedural_map.c			\
		./src/components/procedural_map/draw/draw_procedural_map.c			\
		./src/components/procedural_map/destroy/destroy_procedural_map.c	\
		./src/components/procedural_map/init/init_enemies.c					\
		./src/components/procedural_map/destroy/destroy_enemies.c			\
		./src/components/procedural_map/draw/draw_enemies.c					\
		./src/components/procedural_map/handle_enemy_damage.c				\
		./src/components/procedural_map/move_enemies.c						\
		./src/components/procedural_map/spawn_enemies.c						\
		\
		./src/components/save_menu/event/on_event_save_menu_btn.c			\
		\
		./src/components/select_skin/event/on_event_select_skin_select.c	\
		\
		./src/components/dialog/dialog_renderer.c 							\
		\
		./src/components/select_map/event/on_event_select_map.c				\
		\
		./src/components/settings/events/click_buttons.c 					\
		./src/components/settings/video/click_video.c  						\
		./src/components/settings/audio/click_audio.c 						\
		./src/components/settings/keys/on_click_event.c						\
		./src/components/settings/keys/on_key_event.c						\
		\
		./src/components/projectiles/init_projectiles.c 					\
		./src/components/projectiles/draw_projectile.c 						\
		./src/components/projectiles/destroy_projectile.c 					\
		./src/components/projectiles/register_projectile.c 					\
		./src/components/projectiles/set_bestiary.c 						\
		./src/components/character/set_movement_particle.c 					\
		./src/components/character/event/custom_particle.c 					\
		\
		./src/components/quests/init/init_quests.c 							\
		./src/components/quests/draw/draw_quests.c 							\
		./src/components/quests/destroy/destroy_quest.c 					\
		\
		./src/systems/systems.c 											\
		./src/systems/save.c 												\
		./src/systems/save_utils.c 											\
		./src/systems/music.c 												\
		./src/systems/sound.c


CFLAGS		+=	-Werror -Wextra -Wall -Wno-deprecated
CPPFLAGS	+=	-I./include
LDFLAGS		+=	-L./lib
LDLIBS		+=	-lcsfml-graphics -lcsfml-window \
				-lcsfml-audio -lcsfml-system -lm -lmy

ifeq ($(DEBUG),1)
	CC = clang
	CFLAGS += -g3 -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	 lib	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

lib:
	make -C ./lib

clean:
	$(RM) $(OBJ)
	make -C ./lib clean

fclean: clean
	$(RM) $(NAME)
	make -C ./lib fclean

re: fclean all

.PHONY: all clean fclean re lib
