/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** rpg.h
*/

#ifndef _RPG_H_
#define _RPG_H_

#define EXIT_SUCCESS 0
#define EXIT_ERROR 84
#define SUCCESS 0
#define ERROR -1

#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Graphics/Types.h>
#include <stdbool.h>
#include "my.h"
#include "particle.h"

typedef struct screen_s
{
    sfRenderWindow *wind;
    sfTexture *text;
    sfSprite *sprite;
    sfEvent event;
} screen_t;

typedef enum
{
    boss = 4,
    mini_boss = 7,
    others = 0,
    none,
} meet_enemy;

typedef struct game_object_s
{
    char *name_spr;
    sfSprite *spr;
    sfTexture *text;
    sfIntRect rect;
    sfVector2f pos;
    int life;
    int max_life;
    int physic;
    int magic;
    int lvl;
    int xp;
    int nb_rect;
} game_object_t;

typedef struct button_s
{
    int pos_button_x;
    int pos_button_y;
    int size_x;
    int size_y;
} button_t;

typedef struct scene_s
{
    game_object_t *ent;
    button_t *butt;
    int monster;
    int is_win;
    int turn;
} scene_t;

typedef struct player_s
{
    sfVector2f pos;
    int life;
    int max_life;
    int physics;
    int magic;
    int lvl;
    int xp;
    int max_xp;
    int mana;
    int def;
    int foot;
} player_t;

typedef struct battle_area_s
{
    sfVector2i pos_boss_zone;
    sfVector2i size_boss_zone;
    sfVector2i pos_mini_boss_zone;
    sfVector2i size_mini_boss_zone;
    bool boss;
    bool mini_boss;
} battle_area_t;

typedef struct map_s
{
    player_t player;
    int up;
    int down;
    int right;
    int left;
    battle_area_t battle_area;
    int lenght;
    sfText *text_one;
    sfText *text_two;
    char **map;
} map_t;

typedef struct invent_s
{
    player_t player;
    char **map;
} invent_t;

typedef struct game_s
{
    scene_t *scn;
    screen_t scr;
    int is_error;
    int is_end;
    int nb;
    map_t map;
    invent_t invt;
    sfEvent event;
    sfMusic **music;
    sfView *view;
    prtcl_list_t list;
} rpg_t;

int open_window(char *arg);
void buff_destroy(rpg_t rpg);

char *sentence_create(int nb, char *sentence, int count);
int rpg_loop(rpg_t rpg);

int is_button_pressed(rpg_t rpg, int nb_scn, int nb_button);

rpg_t init_player(rpg_t rpg);
rpg_t init_sprite(rpg_t rpg);
rpg_t init_button(rpg_t rpg);
rpg_t init_pos_ent(rpg_t tpg);
rpg_t init_music(rpg_t rpg);
rpg_t init_rect_ent(rpg_t rpg);
rpg_t init_caract_ent(rpg_t rpg);
rpg_t init_sprite_name_ent(rpg_t rpg);
rpg_t init_game_object_value(rpg_t rpg);
rpg_t init_player_move(rpg_t rpg);

rpg_t game_loop(rpg_t rpg, sfClock *clock);
rpg_t manage_scene(rpg_t rpg, sfClock *clock);

rpg_t fight(rpg_t rpg, int monster, sfClock *clock);
rpg_t display_monster(rpg_t rpg, int monster, sfClock *clock);
rpg_t fight_end_and_level_up(rpg_t rpg);
rpg_t reset_monster(rpg_t rpg);
void display_heal(rpg_t rpg, int value);
void display_life(rpg_t rpg, int ent, sfVector2f pos);
void display_fight_information(rpg_t rpg, int monster);
void display_damage(rpg_t rpg, int pos_display, int value);
void display_sprite(rpg_t rpg, int scn, int nb_spr);
rpg_t player_turn(rpg_t rpg, int monster);
rpg_t enemies_turn(rpg_t rpg, int monster);
int check_fight_action(rpg_t rpg);
rpg_t heal_player(rpg_t rpg, int heal_value);
int random_monster(int monster, int value , int cmpt);
rpg_t manage_fight(rpg_t rpg, sfClock *clock);

rpg_t level_up(rpg_t rpg);
rpg_t display_if_level_up(rpg_t rpg);

void display_background(rpg_t rpg);
rpg_t map_gestion(rpg_t rpg, sfClock *clock);
rpg_t detection_of_battle_zones(rpg_t rpg);
rpg_t player_move_in_the_map(rpg_t rpg);
rpg_t init_battle_area(rpg_t rpg);
rpg_t fs_read_map(char *arg, rpg_t rpg);
rpg_t res_map(rpg_t rpg);

rpg_t manage_how_to_play(rpg_t rpg);

rpg_t manage_music(rpg_t rpg);

rpg_t init_particle_effects(rpg_t rpg);
rpg_t particle_when_click(rpg_t rpg, sfClock *clock);

void quest_display(rpg_t rpg);
rpg_t init_text(rpg_t rpg);

#endif
