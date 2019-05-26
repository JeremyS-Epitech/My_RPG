/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** init_caract_ent
*/

#include "rpg.h"

rpg_t init_def(rpg_t rpg, int entity, int def_physic)
{
    rpg.scn[1].ent[entity].physic = def_physic;
    return (rpg);
}

rpg_t init_attack(rpg_t rpg, int entity, int dmg_physic)
{
    rpg.scn[1].ent[entity].physic = dmg_physic;
    return (rpg);
}

rpg_t init_life_and_lvl(rpg_t rpg, int entity, int life, int lvl)
{
    rpg.scn[1].ent[entity].life = life;
    rpg.scn[1].ent[entity].lvl = lvl;
    return (rpg);
}

rpg_t init_caract_ent(rpg_t rpg)
{
    rpg = init_def(rpg, 4, 50);
    rpg = init_attack(rpg, 4, 60);
    rpg = init_life_and_lvl(rpg, 4, 500, 20);
    rpg.scn[1].ent[4].max_life = 500;
    rpg = init_def(rpg, 5, 0);
    rpg = init_attack(rpg, 5, 20);
    rpg = init_life_and_lvl(rpg, 5, 75, 10);
    rpg.scn[1].ent[5].max_life = 75;
    rpg = init_def(rpg, 6, 20);
    rpg = init_attack(rpg, 6, 30);
    rpg = init_life_and_lvl(rpg, 6, 100, 15);
    rpg.scn[1].ent[6].max_life = 110;
    rpg = init_def(rpg, 7, 20);
    rpg = init_attack(rpg, 7, 49);
    rpg = init_life_and_lvl(rpg, 7, 300, 18);
    rpg.scn[1].ent[7].max_life = 300;
    return (rpg);
}