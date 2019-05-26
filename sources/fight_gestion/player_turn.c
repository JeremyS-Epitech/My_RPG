/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player_turn
*/

#include "rpg.h"

rpg_t check_is_special_enemies(rpg_t rpg, int monster)
{
    if (monster == 4)
        rpg.map.battle_area.boss = true;
    if (monster == 7)
        rpg.map.battle_area.mini_boss = true;
    return (rpg);
}

rpg_t enemies_taken_damage(rpg_t rpg, int monster, int dmg_value)
{
    static int i = 0;
    static int life;

    if (i == 0) {
        if (rpg.scn[1].ent[monster].life == 0)
            rpg.scn[1].ent[monster].life = life;
        else
            life = rpg.scn[1].ent[monster].life;
        i++;
    }
    rpg.scn[1].ent[monster].life -= dmg_value;
    rpg.scn[1].turn = 0;
    if (rpg.scn[1].ent[monster].life <= 0) {
        rpg.scn[1].is_win = 1;
        i = 0;
        rpg.scn[1].ent[monster].life = life;
        rpg.scn[1].turn = 2;
        rpg.map.player.def = 0;
        rpg = check_is_special_enemies(rpg, monster);
    }
    return (rpg);
}

rpg_t check_def(rpg_t rpg)
{
    static int is_def = 0;
    static int nbr_turn = 0;

    if (is_def == 0 && rpg.map.player.def != 0)
        is_def++;
    if (is_def != 0)
        nbr_turn++;
    if (nbr_turn == 5) {
        is_def = 0;
        nbr_turn = 0;
        rpg.map.player.def = 0;
    }
    return (rpg);
}

rpg_t player_turn(rpg_t rpg, int monster)
{
    int action_value = 0;
    int heal_value = rpg.map.player.max_life - rpg.map.player.life;

    action_value = check_fight_action(rpg);
    if (action_value != 0) {
        rpg = check_def(rpg);
        if (action_value == 1)
            rpg = enemies_taken_damage(rpg, monster, rpg.map.player.physics);
        if (action_value == 2) {
            rpg = heal_player(rpg, heal_value);
            rpg.scn[1].turn = 0;
        }
        if (action_value == 3) {
            rpg.map.player.def = 25;
            rpg.scn[1].turn = 0;
            rpg.map.player.mana -= 15;
        }
    }
    return (rpg);
}