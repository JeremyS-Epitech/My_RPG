/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_end_and_level_up
*/

#include "rpg.h"

void display_end(rpg_t rpg)
{
    sfSprite_setPosition(rpg.scn[3].ent[2].spr,
    rpg.scn[3].ent[2].pos);
    sfRenderWindow_drawSprite(rpg.scr.wind, rpg.scn[3].ent[2].spr, NULL);
}

void display_res_xp(rpg_t rpg)
{
    sfFont *font;
    sfText *text;
    char *sentence = NULL;
    sfVector2f pos = {650, 500};

    sentence = "XP +";
    font = sfFont_createFromFile("ressources/text/text.ttf");
    text = sfText_create();
    sfText_setString(text, sentence);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(rpg.scr.wind, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void display_xp(rpg_t rpg)
{
    sfFont *font;
    sfText *text;
    char *sentence = NULL;
    sfVector2f pos = {690, 500};

    display_res_xp(rpg);
    sentence = malloc(sizeof(char *) * (10 + 1));
    sentence = sentence_create(200, sentence, 5);
    font = sfFont_createFromFile("ressources/text/text.ttf");
    text = sfText_create();
    sfText_setString(text, sentence);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(rpg.scr.wind, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void dislpay_result_and_xp(rpg_t rpg, int res)
{
    sfFont *font;
    sfText *text;
    char *sentence = NULL;
    sfVector2f pos = {640, 360};

    if (res == 1) {
        sentence = "YOU WIN!";
        display_xp(rpg);
    }
    else if (res == 2)
        sentence = "YOU LOOSE!";
    font = sfFont_createFromFile("ressources/text/text.ttf");
    text = sfText_create();
    sfText_setString(text, sentence);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(rpg.scr.wind, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

rpg_t fight_end_and_level_up(rpg_t rpg)
{
    static int end = 0;
    static int time = 0;

    if (end == 0) {
        end = rpg.scn[1].is_win;
        rpg.scn[1].is_win = 0;
    }
    if (time < 1000 && end != 0) {
        display_end(rpg);
        dislpay_result_and_xp(rpg, end);
        rpg = display_if_level_up(rpg);
        time++;
    }
    if (time == 1000) {
        time = 0;
        end = 0;
    }
    return (rpg);
}