/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** reset_monster
*/

#include "rpg.h"

rpg_t reset_monster(rpg_t rpg)
{
    for (int i = 1; i != 5; i++)
        rpg.scn[1].ent[i].nb_rect = 0;
    return (rpg);
}