/*
** EPITECH PROJECT, 2019
** MUL_my_rph_2018
** File description:
** init_player
*/

#include "rpg.h"

rpg_t init_player(rpg_t rpg)
{
    rpg.map.player.max_life = 100;
    rpg.map.player.life = 100;
    rpg.map.player.physics = 12;
    rpg.map.player.lvl = 1;
    rpg.map.player.xp = 0;
    rpg.map.player.max_xp = 200;
    rpg.map.player.mana = 75;
    rpg.map.player.def = 0;
    return (rpg);
}