/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_particle_effects
*/

#include "rpg.h"

rpg_t particle_when_click(rpg_t rpg, sfClock *clock)
{
    static int count = 0;
    static sfVector2i mouse_pos;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse_pos = sfMouse_getPosition((sfWindow *)rpg.scr.wind);
        rpg.list = particle_init_pos(rpg.list, mouse_pos.x, mouse_pos.y);
        rpg.list.left_click = 1;
    }
    if (rpg.list.left_click == 1) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 40)
            count++;
        rpg.list = move_particle(rpg.list, clock, mouse_pos);
        rpg.list = print_particle(rpg.list, rpg.scr.wind);
    }
    if (count >= 27) {
        rpg.list.left_click = 0;
        count = 0;
    }
    return (rpg);
}
