/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_fight
*/

#include "rpg.h"

rpg_t tp_player_if_loose(rpg_t rpg)
{
    rpg.scn[3].ent[0].pos.x = -1840;
    rpg.scn[3].ent[0].pos.y = -1740;
    return (rpg);
}

rpg_t manage_fight(rpg_t rpg, sfClock *clock)
{
    static int monster = 0;
    static int cmpt = 0;

    if (rpg.scn[1].monster == 0)
        monster = random_monster(monster, 2, cmpt);
    else
        monster = rpg.scn[1].monster;
    rpg.scn[1].is_win = 0;
    rpg = fight(rpg, monster, clock);
    cmpt = 1;
    if (rpg.scn[1].is_win == 1) {
        rpg.nb = 3;
        cmpt = 0;
        rpg.map.player.xp += 200;
    }
    else if (rpg.scn[1].is_win == 2) {
        rpg.nb = 3;
        cmpt = 0;
        rpg = tp_player_if_loose(rpg);
    }
    return (rpg);
}