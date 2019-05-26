/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** battle_area
*/

#include "rpg.h"

meet_enemy check_player_pos(sfVector2i pos, rpg_t rpg)
{
    if ((pos.x > rpg.map.battle_area.pos_boss_zone.x)
    && (pos.x < (rpg.map.battle_area.pos_boss_zone.x
    + rpg.map.battle_area.size_boss_zone.x))) {
        if ((pos.y > rpg.map.battle_area.pos_boss_zone.y)
        && (pos.y < (rpg.map.battle_area.pos_boss_zone.y
        + rpg.map.battle_area.size_boss_zone.y)))
            return (boss);
    }
    if ((pos.x > rpg.map.battle_area.pos_mini_boss_zone.x)
    && (pos.x < (rpg.map.battle_area.pos_mini_boss_zone.x
    + rpg.map.battle_area.size_mini_boss_zone.x))) {
        if ((pos.y > rpg.map.battle_area.pos_mini_boss_zone.y)
        && (pos.y < (rpg.map.battle_area.pos_mini_boss_zone.y
        + rpg.map.battle_area.size_mini_boss_zone.y)))
            return (mini_boss);
    }
    return (none);
}

rpg_t other_enemy_battle(rpg_t rpg)
{
    if (rpg.map.player.foot >= 13) {
        rpg.scn[1].monster = 0;
        rpg.nb = 1;
    }
    return (rpg);
}

rpg_t is_player_fight(rpg_t rpg)
{
    sfVector2i pos;

    pos.x = -(rpg.scn[3].ent[0].pos.x);
    pos.y = -(rpg.scn[3].ent[0].pos.y);
    if (check_player_pos(pos, rpg) == boss
    && rpg.map.battle_area.boss != true) {
        rpg.scn[1].monster = 4;
        rpg.nb = 1;
    }
    else if (check_player_pos(pos, rpg) == mini_boss
    && rpg.map.battle_area.mini_boss != true) {
        rpg.scn[1].monster = 7;
        rpg.nb = 1;
    }
    else
        rpg = other_enemy_battle(rpg);
    return (rpg);
}

rpg_t detection_of_battle_zones(rpg_t rpg)
{
    rpg = is_player_fight(rpg);
    quest_display(rpg);
    return (rpg);
}