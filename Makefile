##
## EPITECH PROJECT, 2019
## MUL_my_rpg
## File description:
## Makefile
##

NAME	=	my_rpg

SOURCES	=	\
			sources/main.c						\
			sources/is_button_pressed.c 				\
			sources/sentence_create.c				\
			sources/manage_how_to_play.c				\
			sources/window_management/buff_destroy.c		\
			sources/window_management/open_window.c			\
			sources/init_function/init_game_object_value.c 		\
			sources/init_function/init_sprite_name_ent.c 		\
			sources/init_function/init_pos_ent.c 			\
			sources/init_function/init_rect_ent.c 			\
			sources/init_function/init_sprite.c 			\
			sources/init_function/init_button.c 			\
			sources/init_function/init_caract_ent.c 		\
			sources/init_function/init_player.c 			\
			sources/init_function/init_music.c			\
			sources/init_function/init_battle_area.c		\
			sources/map_gestion/init_player_move.c		\
			sources/scene_management/rpg_loop.c			\
			sources/scene_management/manage_scene.c			\
			sources/scene_management/game_loop.c			\
			sources/scene_management/manage_music.c			\
			sources/fight_gestion/fight.c 				\
			sources/fight_gestion/reset_monster.c 			\
			sources/fight_gestion/level_up.c 			\
			sources/fight_gestion/fight_end_and_level_up.c		\
			sources/map_gestion/map_management.c			\
			sources/map_gestion/fs_read_map.c			\
			sources/map_gestion/battle_area.c			\
			sources/map_gestion/player_move_in_the_map.c		\
			sources/map_gestion/quest_display.c			\
			sources/map_gestion/collision_with_corner.c		\
			sources/display_function/display_fight_information.c 	\
			sources/display_function/display_monster.c 		\
			sources/display_function/display_if_level_up.c 		\
			sources/particle_effects/init_particle.c		\
			sources/particle_effects/particle.c			\
			sources/particle_effects/particle_when_click.c		\
			sources/particle_effects/move_particle.c		\
			sources/particle_effects/sand_storm.c			\
			sources/display_function/display_sprite.c		\
			sources/fight_gestion/player_turn.c 			\
			sources/fight_gestion/enemies_turn.c 			\
			sources/fight_gestion/check_fight_action.c		\
			sources/fight_gestion/heal_player.c 			\
			sources/fight_gestion/random_monster.c 			\
			sources/fight_gestion/manage_fight.c 			\

OBJECTS	=	$(SOURCES:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Iinclude

LDFLAGS	=	-lmy -L./lib/my -lm

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJECTS)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJECTS) $(LDFLAGS) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	$(RM) $(OBJECTS)
	make clean -C lib/my/

fclean:	clean
	$(RM) $(NAME)
	make fclean -C lib/my/

re: fclean all
