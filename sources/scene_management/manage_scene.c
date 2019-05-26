/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** manage_scene
*/

#include "rpg.h"

rpg_t click_on_menu_button(rpg_t rpg)
{
    if (is_button_pressed(rpg, 0, 1) == 1) {
        if (rpg.nb < 1)
            rpg.nb = 3;
    }
    if (is_button_pressed(rpg, 0, 3) == 1)
        sfRenderWindow_close(rpg.scr.wind);
    return (rpg);
}

rpg_t manage_scene_one(rpg_t rpg, sfClock *clock)
{
    static int count = 0;

    rpg = click_on_menu_button(rpg);
    if (is_button_pressed(rpg, 0, 2) == 1) {
        if (rpg.nb < 1)
            rpg.nb = 2;
    }
    if (count != 0) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 1100) {
            rpg.nb = count;
            count = 0;
            return (rpg);
        }
    }
    if (rpg.nb != 0) {
        count = rpg.nb;
        rpg.nb = 0;
        sfClock_restart(clock);
    }
    return (rpg);
}

rpg_t manage_tuto(rpg_t rpg, sfClock *clock)
{
    (void)(clock);
    rpg = manage_how_to_play(rpg);
    sfSprite_setPosition(rpg.scn[2].ent[0].spr, rpg.scn[2].ent[0].pos);
    sfRenderWindow_drawSprite(rpg.scr.wind, rpg.scn[2].ent[0].spr, NULL);
    return (rpg);
}

rpg_t manage_map_one(rpg_t rpg, sfClock *clock)
{
    rpg = reset_monster(rpg);
    rpg = detection_of_battle_zones(rpg);
    rpg = map_gestion(rpg, clock);
    rpg = fight_end_and_level_up(rpg);
    return (rpg);
}

rpg_t manage_scene(rpg_t rpg, sfClock *clock)
{
    rpg_t (*scan_scene)(rpg_t rpg, sfClock *clock);
    void(*sauv[5]);

    rpg = manage_music(rpg);
    sauv[0] = manage_scene_one;
    sauv[1] = manage_fight;
    sauv[2] = manage_tuto;
    sauv[3] = manage_map_one;
    sauv[4] = NULL;
    scan_scene = sauv[rpg.nb];
    rpg = (*scan_scene)(rpg, clock);
    return (rpg);
}
