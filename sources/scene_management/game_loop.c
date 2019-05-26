/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_loop
*/

#include "rpg.h"

rpg_t game_loop(rpg_t rpg, sfClock *clock)
{
    sfRenderWindow_clear(rpg.scr.wind, sfBlack);
    sfSprite_setTextureRect(rpg.scn[rpg.nb].ent[0].spr,
    rpg.scn[rpg.nb].ent[0].rect);
    sfRenderWindow_drawSprite(rpg.scr.wind, rpg.scn[rpg.nb].ent[0].spr, NULL);
    rpg = manage_scene(rpg, clock);
    rpg = particle_when_click(rpg, clock);
    sfRenderWindow_display(rpg.scr.wind);
    return (rpg);
}
