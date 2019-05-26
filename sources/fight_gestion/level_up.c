/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** level_up
*/

#include "rpg.h"

rpg_t level_up(rpg_t rpg)
{
    rpg.map.player.max_life += 10;
    rpg.map.player.life = rpg.map.player.max_life;
    rpg.map.player.physics += 2;
    rpg.map.player.lvl++;
    rpg.map.player.xp = 0;
    rpg.map.player.max_xp += 100;
    rpg.map.player.mana = 75;
    return (rpg);
}