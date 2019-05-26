/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** manage_player_move
*/

#include "rpg.h"

rpg_t res_map(rpg_t rpg)
{
    if (-rpg.scn[3].ent[0].pos.y <= 0)
        rpg.scn[3].ent[0].pos.y = 0;
    if (-rpg.scn[3].ent[0].pos.y >= 4600)
        rpg.scn[3].ent[0].pos.y = -4600;
    if (-rpg.scn[3].ent[0].pos.x <= 0)
        rpg.scn[3].ent[0].pos.x = 0;
    if (-rpg.scn[3].ent[0].pos.x >= 4092)
        rpg.scn[3].ent[0].pos.x = -4092;
     return (rpg);
}
