/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** random_nbr
*/

#include "rpg.h"

int random_monster(int monster, int value , int cmpt)
{
    if (cmpt == 0) {
        monster = rand() % value;
        monster += 5;
    }
    return (monster);
}