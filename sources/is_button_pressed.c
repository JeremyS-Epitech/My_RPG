/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** is_button_pressed
*/

#include "rpg.h"

int check_pos(sfVector2i pos, rpg_t rpg, int nb_scn, int nb_button)
{
    int is_pressed = 0;
    int x = rpg.scn[nb_scn].butt[nb_button].pos_button_x;
    int y = rpg.scn[nb_scn].butt[nb_button].pos_button_y;
    int size_x = rpg.scn[nb_scn].butt[nb_button].size_x;
    int size_y = rpg.scn[nb_scn].butt[nb_button].size_y;

    if ((pos.x > x) && (pos.x < (x + size_x))) {
        if ((pos.y > y) && (pos.y < (y + size_y)))
            is_pressed++;
    }
    return (is_pressed);
}

int is_button_pressed(rpg_t rpg, int nb_scn, int nb_button)
{
    sfVector2i pos;
    int is_pressed = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pos = sfMouse_getPosition((sfWindow *)rpg.scr.wind);
        is_pressed = check_pos(pos, rpg, nb_scn, nb_button);
    }
    return (is_pressed);
}
