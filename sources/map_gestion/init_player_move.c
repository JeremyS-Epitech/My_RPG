/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_player_move
*/

#include "rpg.h"

rpg_t init_player_move(rpg_t rpg)
{
    if (rpg.map.left == 1)
        rpg.scn[3].ent[1].rect.top = 48;
    if (rpg.map.right == 1)
        rpg.scn[3].ent[1].rect.top = 96;
    if (rpg.map.up == 1)
        rpg.scn[3].ent[1].rect.top = 144;
    if (rpg.map.down == 1)
        rpg.scn[3].ent[1].rect.top = 0;
    return (rpg);
}