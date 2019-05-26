/*
** EPITECH PROJECT, 2019
** sand_storm
** File description:
** function handling sand_storm
*/

#include "particle.h"

sand_storm_list_t init_sand_storm(void)
{
    sand_storm_list_t list;

    list.plist = malloc(sizeof(square_particule_t) * 2600);
    list.number = 2600;
    return (list);
}

sand_storm_list_t init_sand(sand_storm_list_t list, sfVideoMode vm)
{
    sfVector2f pos;
    unsigned int x = 0;
    unsigned int y = 0;

    for (int i = 0; i != list.number; i++) {
        pos.x = x + rand() % 20;
        pos.y = y + rand() % 20;
        list.plist[i].square = sfRectangleShape_create();
        sfRectangleShape_setPosition(list.plist[i].square, pos);
        sfRectangleShape_setFillColor(list.plist[i].square, sfYellow);
        sfRectangleShape_setSize\
(list.plist[i].square, (sfVector2f) {rand() % 4, rand() % 4});
        x += 20;
        if (x > vm.width + 0) {
            y += 20;
            x = 0;
        }
    }
    return (list);
}

sand_storm_list_t move_sand(sand_storm_list_t list, sfVideoMode vm)
{
    sfVector2f pos;

    for (int i = 0; i != list.number; i++) {
        pos = sfRectangleShape_getPosition(list.plist[i].square);
        pos.x += 2;
        if (pos.x > vm.width)
            pos.x -= vm.width;
        sfRectangleShape_setPosition(list.plist[i].square, pos);
    }
    return (list);
}

void put_sand_storm(sand_storm_list_t list, sfRenderWindow *window)
{
    for (int i = 0; i != list.number; i++) {
        sfRenderWindow_drawRectangleShape(window, list.plist[i].square, NULL);
    }
}
