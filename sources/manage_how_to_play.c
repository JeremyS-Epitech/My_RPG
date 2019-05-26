/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** manage_scene
*/

#include "rpg.h"

rpg_t manage_how_to_play(rpg_t rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        rpg.scn[2].ent[0].pos.x += 5;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        rpg.scn[2].ent[0].pos.x -= 5;
    return (rpg);
}