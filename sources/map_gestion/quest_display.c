/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** battle_area
*/

#include "rpg.h"

sfText *init_quest_one(void)
{
    sfFont *font;
    sfText *text;
    sfVector2f pos = {50, 50};

    font = sfFont_createFromFile("ressources/text/sixty.ttf");
    text = sfText_create();
    sfText_setString(text, "FIRST QUEST\nDEFEAT THE ENEMY ON THE BRIDGE");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfRed);
    return (text);
}

sfText *init_quest_two(void)
{
    sfFont *font;
    sfText *text;
    sfVector2f pos = {50, 50};

    font = sfFont_createFromFile("ressources/text/sixty.ttf");
    text = sfText_create();
    sfText_setString(text, "SECOND QUEST\nDEFEAT THE ENEMY IN THE CASTLE");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfRed);
    return (text);
}

rpg_t init_text(rpg_t rpg)
{
    rpg.map.text_one = init_quest_one();
    rpg.map.text_two = init_quest_two();
    return (rpg);
}

void quest_display(rpg_t rpg)
{
    if (rpg.map.battle_area.mini_boss != true) {
        sfRenderWindow_drawText(rpg.scr.wind,
        rpg.map.text_one, NULL);
    }
    else if (rpg.map.battle_area.boss != true) {
        sfRenderWindow_drawText(rpg.scr.wind,
        rpg.map.text_two, NULL);
    }
}
