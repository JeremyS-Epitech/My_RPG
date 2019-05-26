/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** enemies_turn
*/

#include "rpg.h"

rpg_t reset_life_and_def(rpg_t rpg, int monster)
{
    rpg.map.player.def = 0;
    rpg.map.player.mana = 75;
    rpg.scn[1].ent[monster].life = rpg.scn[1].ent[monster].max_life;
    return (rpg);
}

rpg_t player_taken_damage(rpg_t rpg, int dmg_value, int monster)
{
    static int i = 0;
    static int life;

    if (i == 0) {
        if (rpg.map.player.life == 0)
            rpg.map.player.life = life;

        else
            life = rpg.map.player.life;
        i++;
    }
    rpg.map.player.life -= dmg_value;
    rpg.scn[1].turn = 1;
    if (rpg.map.player.life <= 0) {
        rpg.scn[1].is_win = 2;
        i = 0;
        rpg.map.player.life = life;
        rpg.scn[1].turn = 2;
        rpg = reset_life_and_def(rpg, monster);
    }
    return (rpg);
}

rpg_t update_mana(rpg_t rpg)
{
    if (rpg.map.player.mana < 75)
        rpg.map.player.mana += 5;
    if (rpg.map.player.mana > 75)
        rpg.map.player.mana = 75;
    return (rpg);
}

rpg_t enemies_turn(rpg_t rpg, int monster)
{
    static int enemies_turn = 0;
    int dmg_value = 0;

    if (enemies_turn >= 300) {
        if (rpg.map.player.def != 0)
            dmg_value = (rpg.scn[1].ent[monster].physic * 75) / (100);
        else
            dmg_value = rpg.scn[1].ent[monster].physic;
        rpg = player_taken_damage(rpg, dmg_value, monster);
        rpg.scn[1].turn = 2;
        enemies_turn = 0;
        rpg = update_mana(rpg);
    }
    else
        enemies_turn++;
    return (rpg);
}