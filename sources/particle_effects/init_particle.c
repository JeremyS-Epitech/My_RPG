/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_particle_effects
*/

#include "rpg.h"

rpg_t init_particle_effects(rpg_t rpg)
{
    rpg.list = init_list(40);
    rpg.list = particle_init(90, 360, 4, rpg.list);
    return (rpg);
}
