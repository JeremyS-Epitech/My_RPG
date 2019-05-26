/*
** EPITECH PROJECT, 2019
** particule.h
** File description:
** handle particule
*/

#ifndef _PARTICLE_H_
#define _PARTICLE_H_

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
#include <SFML/Config.h>
#include <math.h>
#include "my.h"

typedef struct particle_s
{
    sfCircleShape *circle;
    sfVector2f position;
    int opacity;
    float speed;
    float dir;
    bool state;
} particle_t;

typedef struct prtcl_list_s
{
    sfTime time;
    int ms;
    int number;
    particle_t *plist;
    bool error;
    bool end;
    int left_click;
} prtcl_list_t;

typedef struct square_particule_s
{
    sfRectangleShape *square;
} square_particule_t;

typedef struct sand_storm_list_s
{
    int number;
    square_particule_t *plist;
} sand_storm_list_t;

prtcl_list_t init_list(int number);
prtcl_list_t particle_init(int angle, int spread, int speed, prtcl_list_t list);
prtcl_list_t particle_init_pos(prtcl_list_t list, int x, int y);
prtcl_list_t move_particle(prtcl_list_t list, sfClock *clock, sfVector2i ms);
prtcl_list_t move_pos(prtcl_list_t list, sfVector2i ms, sfVector2f pos, int i);
prtcl_list_t print_particle(prtcl_list_t list, sfRenderWindow *window);

sand_storm_list_t init_sand_storm(void);
sand_storm_list_t init_sand(sand_storm_list_t list, sfVideoMode vm);
sand_storm_list_t move_sand(sand_storm_list_t list, sfVideoMode vm);
void put_sand_storm(sand_storm_list_t list, sfRenderWindow *window);
#endif
