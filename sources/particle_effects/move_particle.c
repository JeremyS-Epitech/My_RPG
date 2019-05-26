/*
** EPITECH PROJECT, 2019
** particle
** File description:
** function handling particle
*/

#include "rpg.h"

prtcl_list_t move_pos(prtcl_list_t list, sfVector2i ms, sfVector2f pos, int i)
{
    pos = sfCircleShape_getPosition(list.plist[i].circle);
    if (pos.x >= (ms.x + 50) || pos.x <= (ms.x - 50))
        pos.x = ms.x;
    if (pos.y >= (ms.y + 50) || pos.y <= (ms.y - 50))
        pos.y = ms.y;
    pos.x += -list.plist[i].speed * cosf(list.plist[i].dir);
    pos.y += list.plist[i].speed * sinf(list.plist[i].dir);
    sfCircleShape_setPosition(list.plist[i].circle, pos);
    return (list);
}
