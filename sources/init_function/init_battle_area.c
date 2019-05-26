/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_battle_area
*/

#include "rpg.h"

rpg_t init_battle_area(rpg_t rpg)
{
    sfVector2i pos_boss_zone = {790, 131};
    sfVector2i size_boss_zone = {147, 58};
    sfVector2i pos_mini_boss_zone = {654, 474};
    sfVector2i size_mini_boss_zone = {265, 116};

    rpg.map.player.foot = 0;
    rpg.map.battle_area.boss = false;
    rpg.map.battle_area.pos_boss_zone = pos_boss_zone;
    rpg.map.battle_area.size_boss_zone = size_boss_zone;
    rpg.map.battle_area.pos_mini_boss_zone = pos_mini_boss_zone;
    rpg.map.battle_area.size_mini_boss_zone = size_mini_boss_zone;
    return (rpg);
}