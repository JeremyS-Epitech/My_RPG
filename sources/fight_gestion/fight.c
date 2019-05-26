/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight
*/

#include "rpg.h"

int check_if_def(rpg_t rpg, int turn)
{
    if (rpg.map.player.def != 0 && turn == 2)
        return (3);
    if (rpg.map.player.def != 0 && turn == 0)
        return (1);
    if (rpg.map.player.def == 0 && turn == 2)
        return (2);
    if (rpg.map.player.def == 0 && turn == 0)
        return (0);
    return (0);
}

rpg_t fight(rpg_t rpg, int monster, sfClock *clock)
{
    static int scn_status = 2;

    scn_status = check_if_def(rpg, rpg.scn[1].turn);
    display_sprite(rpg, 1, scn_status);
    display_fight_information(rpg, monster);
    rpg = display_monster(rpg, monster, clock);
    if (rpg.scn[1].turn == 2) {
        scn_status = 2;
        rpg = player_turn(rpg, monster);
    }
    if (rpg.scn[1].turn == 0) {
        scn_status = 0;
        rpg = enemies_turn(rpg, monster);
    }
    rpg.map.player.foot = 0;
    return (rpg);
}