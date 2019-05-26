/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** init_game_object_value
*/

#include "rpg.h"

rpg_t init_music(rpg_t rpg)
{
    rpg.music = malloc(sizeof(rpg.music) * 4);
    rpg.music[0] = sfMusic_createFromFile("ressources/music/menu.ogg");
    rpg.music[1] = sfMusic_createFromFile("ressources/music/battle.ogg");
    rpg.music[2] = sfMusic_createFromFile("ressources/music/sand.ogg");
    rpg.music[3] = NULL;
    sfMusic_play(rpg.music[0]);
    return (rpg);
}