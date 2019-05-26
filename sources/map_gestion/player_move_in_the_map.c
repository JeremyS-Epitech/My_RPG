/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** manage_player_move
*/

#include "rpg.h"

rpg_t left_move(rpg_t rpg)
{
    rpg.map.player.pos.x += 0.5;
    rpg.scn[3].ent[0].pos.x += 0.5;
    return (rpg);
}

rpg_t right_move(rpg_t rpg)
{
    rpg.map.player.pos.x -= 0.5;
    rpg.scn[3].ent[0].pos.x -= 0.5;
    return (rpg);
}

rpg_t up_move(rpg_t rpg)
{
    rpg.map.player.pos.y += 0.5;
    rpg.scn[3].ent[0].pos.y += 0.5;
    return (rpg);
}

rpg_t down_move(rpg_t rpg)
{
    rpg.map.player.pos.y -= 0.5;
    rpg.scn[3].ent[0].pos.y -= 0.5;
    return (rpg);
}

rpg_t player_move_in_the_map(rpg_t rpg)
{
    if (rpg.map.left == 1)
        rpg = left_move(rpg);
    if (rpg.map.right == 1)
        rpg = right_move(rpg);
    if (rpg.map.up == 1)
        rpg = up_move(rpg);
    if (rpg.map.down == 1)
        rpg = down_move(rpg);
    rpg = res_map(rpg);
    return (rpg);
}