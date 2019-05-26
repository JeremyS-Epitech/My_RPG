/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** rpg
*/

#include "rpg.h"

rpg_t close_event(rpg_t rpg, sfEvent event)
{
    static int opt = 0;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(rpg.scr.wind);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        rpg.nb = 0;
    if (sfKeyboard_isKeyPressed(sfKeyL) && opt == 0) {
        for (int count = 0; count != 18; count++)
            rpg = level_up(rpg);
        opt ++;
    }
    return (rpg);
}

int rpg_loop(rpg_t rpg)
{
    sfEvent event;
    sfClock *clock = sfClock_create();

    srand(2);
    rpg.nb = 0;
    rpg = init_game_object_value(rpg);
    if (rpg.is_error != 0)
        return (ERROR);
    while (sfRenderWindow_isOpen(rpg.scr.wind)) {
        while (sfRenderWindow_pollEvent(rpg.scr.wind, &event))
            rpg = close_event(rpg, event);
        rpg = game_loop(rpg, clock);
    }
    sfRenderWindow_close(rpg.scr.wind);
    buff_destroy(rpg);
    return (SUCCESS);
}
