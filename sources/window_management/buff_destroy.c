/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** buff_destroy
*/

#include "rpg.h"

void buff_destroy(rpg_t rpg)
{
    for (int i = 0; rpg.music[i] != NULL; i++)
        sfMusic_destroy(rpg.music[i]);
    sfRenderWindow_destroy(rpg.scr.wind);
    sfText_destroy(rpg.map.text_one);
    sfText_destroy(rpg.map.text_two);
}
