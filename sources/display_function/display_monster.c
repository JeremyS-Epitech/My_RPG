/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_monster
*/

#include "rpg.h"

rpg_t change_rect(rpg_t rpg, int monster)
{
    if (rpg.scn[1].ent[monster].nb_rect == 0) {
        if (rpg.scn[1].ent[monster].rect.left < 7098)
            rpg.scn[1].ent[monster].rect.left += 507;
        else if (rpg.scn[1].ent[monster].rect.left == 7098)
            rpg.scn[1].ent[monster].nb_rect = 1;
    }
    else if (rpg.scn[1].ent[monster].nb_rect == 1) {
        if (rpg.scn[1].ent[monster].rect.left > 0)
            rpg.scn[1].ent[monster].rect.left -= 507;
        else if (rpg.scn[1].ent[monster].rect.left == 0)
            rpg.scn[1].ent[monster].nb_rect = 0;
    }
    return (rpg);
}

rpg_t change_rect_fairy(rpg_t rpg, int monster, sfClock *clock)
{
    static int time_value = 0;

    if (rpg.scn[1].ent[monster].rect.left <= 3304)
        time_value = 80;
    else
        time_value = 190;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > (time_value)) {
        if (rpg.scn[1].ent[monster].rect.left == 0\
|| rpg.scn[1].ent[monster].rect.left < 14868)
            rpg.scn[1].ent[monster].rect.left += 236;
        else if (rpg.scn[1].ent[monster].rect.left >= 14868)
            rpg.scn[1].ent[monster].rect.left = 0;
        sfClock_restart(clock);
    }
    return (rpg);
}

rpg_t change_rect_little_boss(rpg_t rpg, int monster, sfClock *clock)
{
    static int time_value = 170;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > (time_value)) {
        if (rpg.scn[1].ent[monster].rect.left == 0\
|| rpg.scn[1].ent[monster].rect.left < 6800)
            rpg.scn[1].ent[monster].rect.left += 425;
        else if (rpg.scn[1].ent[monster].rect.left >= 6800)
            rpg.scn[1].ent[monster].rect.left = 0;
        sfClock_restart(clock);
    }
    return (rpg);
}

rpg_t change_rect_glue(rpg_t rpg, int monster, sfClock *clock)
{
    static int time_value = 150;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > (time_value)) {
        if (rpg.scn[1].ent[monster].rect.left == 0\
|| rpg.scn[1].ent[monster].rect.left < 2451)
            rpg.scn[1].ent[monster].rect.left += 129;
        else if (rpg.scn[1].ent[monster].rect.left >= 2451)
            rpg.scn[1].ent[monster].rect.left = 0;
        sfClock_restart(clock);
    }
    return (rpg);
}

rpg_t display_monster(rpg_t rpg, int monster, sfClock *clock)
{
    display_sprite(rpg, 1, monster);
    if (monster == 4) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > (100)) {
            rpg = change_rect(rpg, monster);
            sfClock_restart(clock);
        }
    }
    if (monster == 5)
        rpg = change_rect_fairy(rpg, monster, clock);
    if (monster == 6)
        rpg = change_rect_glue(rpg, monster, clock);
    if (monster == 7)
        rpg = change_rect_little_boss(rpg, monster, clock);
    return (rpg);
}