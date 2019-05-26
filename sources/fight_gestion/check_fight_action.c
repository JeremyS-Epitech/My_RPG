/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_fight_action
*/

#include "rpg.h"

int check_fight_action(rpg_t rpg)
{
    if (is_button_pressed(rpg, 1, 0) == 1)
        return (1);
    if (is_button_pressed(rpg, 1, 1) == 1 && rpg.map.player.mana >= 25)
        return (2);
    if (is_button_pressed(rpg, 1, 2) == 1 && rpg.map.player.mana >= 15)
        return (3);
    return (0);
}