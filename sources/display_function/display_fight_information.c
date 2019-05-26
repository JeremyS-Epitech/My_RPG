/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_fight_information
*/

#include "rpg.h"

void display_sentence_nbr(rpg_t rpg, sfVector2f pos, int nbr)
{
    sfFont *font;
    sfText *text;
    char *sentence = NULL;

    sentence = malloc(sizeof(char *) * (10 + 1));
    sentence = sentence_create(nbr, sentence, 5);
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

void display_fight_information(rpg_t rpg, int monster)
{
    sfVector2f player_mana = {1170, 530};
    sfVector2f pos = {50, 200};
    sfVector2f pos_life = {60, 540};

    display_sentence_nbr(rpg, pos, rpg.scn[1].ent[monster].life);
    display_sentence_nbr(rpg, player_mana, rpg.map.player.mana);
    display_sentence_nbr(rpg, pos_life, rpg.map.player.life);
}