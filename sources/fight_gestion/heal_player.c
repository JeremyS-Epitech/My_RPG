/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** heal_player
*/

#include "rpg.h"

rpg_t heal_player(rpg_t rpg, int heal_value)
{
    rpg.map.player.life += heal_value;
    if (rpg.map.player.life > rpg.map.player.max_life)
        rpg.map.player.life = rpg.map.player.max_life;
    rpg.map.player.mana -= 25;
    return (rpg);
}