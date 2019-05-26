/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** manage_scene
*/

#include "rpg.h"

rpg_t move_player_sprite(rpg_t rpg)
{
    static int i = 0;

    if (i == 0)
        rpg.scn[3].ent[1].rect.left -= 48;
    if (i == 2)
        rpg.scn[3].ent[1].rect.left += 96;
    if (i == 4)
        rpg.scn[3].ent[1].rect.left = 0;
    i++;
    if (i >= 6) {
        rpg.map.left = 0;
        rpg.map.right = 0;
        rpg.map.up = 0;
        rpg.map.down = 0;
        rpg.scn[3].ent[1].rect.left = 48;
        rpg.map.player.foot += 3;
        i = 0;
    }
    return (rpg);
}

rpg_t display_player(rpg_t rpg, sfClock *clock)
{
    sfSprite_setTextureRect(rpg.scn[3].ent[1].spr, rpg.scn[3].ent[1].rect);
    sfSprite_setPosition(rpg.scn[3].ent[1].spr, rpg.scn[3].ent[1].pos);
    sfRenderWindow_drawSprite(rpg.scr.wind, rpg.scn[3].ent[1].spr, NULL);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 70) {
        rpg = move_player_sprite(rpg);
        sfClock_restart(clock);
    }
    return (rpg);
}

void display_background(rpg_t rpg)
{
    sfSprite_setPosition(rpg.scn[3].ent[0].spr,
    rpg.scn[3].ent[0].pos);
}

rpg_t get_key_pressed(rpg_t rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && rpg.map.left != 1\
&& rpg.map.right != 1 && rpg.map.down != 1 && rpg.map.up != 1)
        rpg.map.left = 1;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && rpg.map.left != 1\
&& rpg.map.right != 1 && rpg.map.down != 1 && rpg.map.up != 1)
        rpg.map.right = 1;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && rpg.map.left != 1\
&& rpg.map.right != 1 && rpg.map.down != 1 && rpg.map.up != 1)
        rpg.map.up = 1;
    if (sfKeyboard_isKeyPressed(sfKeyDown) && rpg.map.left != 1\
&& rpg.map.right != 1 && rpg.map.down != 1 && rpg.map.up != 1)
        rpg.map.down = 1;
    rpg = init_player_move(rpg);
    return (rpg);
}

rpg_t map_gestion(rpg_t rpg, sfClock *clock)
{
    display_background(rpg);
    if (rpg.map.left == 1 || rpg.map.right == 1\
|| rpg.map.up == 1 || rpg.map.down == 1) {
        rpg = player_move_in_the_map(rpg);
        rpg = display_player(rpg, clock);
    } else {
        rpg = get_key_pressed(rpg);
        sfSprite_setTextureRect(rpg.scn[3].ent[1].spr, rpg.scn[3].ent[1].rect);
        sfSprite_setPosition(rpg.scn[3].ent[1].spr, rpg.scn[3].ent[1].pos);
        rpg.scn[3].ent[1].rect.left = 48;
        sfRenderWindow_drawSprite(rpg.scr.wind, rpg.scn[3].ent[1].spr, NULL);
    }
    return (rpg);
}
