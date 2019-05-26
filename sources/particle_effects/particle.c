/*
** EPITECH PROJECT, 2019
** particle
** File description:
** function handling particle
*/

#include "rpg.h"

prtcl_list_t init_list(int number)
{
    prtcl_list_t list;

    list.plist = malloc(sizeof(particle_t) * (number + 1));
    if (list.plist == NULL)
        return (list);
    list.number = number;
    return (list);
}

prtcl_list_t particle_init(int angle, int spread, int speed, prtcl_list_t list)
{
    for (int i = 0; i != list.number; i++) {
        list.plist[i].circle = sfCircleShape_create();
        sfCircleShape_setRadius(list.plist[i].circle, 5);
        if (i % 3 == 0)
            sfCircleShape_setFillColor(list.plist[i].circle,
            sfColor_fromRGB(135, 206, 235));
        else if (i % 3 == 1)
            sfCircleShape_setFillColor(list.plist[i].circle,
            sfColor_fromRGB(135, 206, 250));
        else
            sfCircleShape_setFillColor(list.plist[i].circle,
            sfColor_fromRGB(176, 224, 230));
        list.plist[i].dir = rand() % spread + angle;
        list.plist[i].speed = rand() % speed + 2;
    }
    return (list);
}

prtcl_list_t particle_init_pos(prtcl_list_t list, int x, int y)
{
    sfVector2f pos = {x, y};

    for (int i = 0; i != list.number; i++)
        sfCircleShape_setPosition(list.plist[i].circle, pos);
    return (list);
}

prtcl_list_t move_particle(prtcl_list_t list, sfClock *clock, sfVector2i mouse)
{
    sfVector2f pos;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 40) {
        for (int i = 0; i != list.number; i++)
            list = move_pos(list, mouse, pos, i);
        sfClock_restart(clock);
    }
    return (list);
}

prtcl_list_t print_particle(prtcl_list_t list, sfRenderWindow *window)
{
    for (int i = 0; i != list.number; i++)
        sfRenderWindow_drawCircleShape(window, list.plist[i].circle, NULL);
    return (list);
}
