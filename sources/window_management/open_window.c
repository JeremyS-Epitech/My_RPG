/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** open_window
*/

#include "rpg.h"

int init_screen(rpg_t rpg)
{
    rpg = init_particle_effects(rpg);
    rpg.is_error = rpg_loop(rpg);
    if (rpg.is_error != 0)
        return (ERROR);
    return (SUCCESS);
}

int open_window(char *arg)
{
    sfVideoMode mode = { 1300, 800, 32 };
    rpg_t rpg;

    rpg = fs_read_map(arg, rpg);
    if (rpg.map.map == NULL)
        return (1);
    rpg.map.left = 0;
    rpg.map.right = 0;
    rpg.map.up = 0;
    rpg.map.down = 0;
    rpg.is_error = 0;
    rpg.scr.wind = sfRenderWindow_create(mode, "RPG", sfClose, NULL);
    if (!rpg.scr.wind)
        return (ERROR);
    rpg.is_error = init_screen(rpg);
    if (rpg.is_error != 0)
        return (ERROR);
    return (SUCCESS);
}