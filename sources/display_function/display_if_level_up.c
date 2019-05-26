/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** diaplay_if_level_up
*/

#include "rpg.h"

void display_caract_up(rpg_t rpg, sfVector2f pos, char *sentence, int size)
{
    sfFont *font;
    sfText *text;

    font = sfFont_createFromFile("ressources/text/text.ttf");
    text = sfText_create();
    sfText_setString(text, sentence);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(rpg.scr.wind, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

rpg_t display_cara(rpg_t rpg)
{
    sfVector2f pos_level_up = {610, 200};
    sfVector2f pos_life = {900, 360};
    sfVector2f pos_lvl = {900, 480};
    sfVector2f pos_dmg = {900, 420};

    display_caract_up(rpg, pos_level_up, "LEVEL UP!", 60);
    display_caract_up(rpg, pos_life, "MAX_LIFE + 10", 35);
    display_caract_up(rpg, pos_dmg, "DMG + 2", 35);
    display_caract_up(rpg, pos_lvl, "LVL + 1", 35);
    return (rpg);
}

rpg_t display_if_level_up(rpg_t rpg)
{
    static int res = 0;
    static int time = 0;

    if (rpg.map.player.xp >= rpg.map.player.max_xp) {
        res = 1;
        rpg = level_up(rpg);
    }
    if (res == 1 && time < 100) {
        display_cara(rpg);
        time++;
    }
    if (time == 100) {
        time = 0;
        res = 0;
    }
    return (rpg);
}