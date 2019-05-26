/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_sprite
*/

#include "rpg.h"

void display_sprite(rpg_t rpg, int scn, int nb_spr)
{
    sfSprite_setPosition(rpg.scn[scn].ent[nb_spr].spr,
    rpg.scn[scn].ent[nb_spr].pos);
    sfSprite_setTextureRect(rpg.scn[1].ent[nb_spr].spr,
    rpg.scn[scn].ent[nb_spr].rect);
    sfRenderWindow_drawSprite(rpg.scr.wind,
    rpg.scn[scn].ent[nb_spr].spr, NULL);
}