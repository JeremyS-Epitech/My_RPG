/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sentence_create
*/

#include "rpg.h"

char *sentence_create(int nb, char *sentence, int count)
{
    sentence[0] = ' ';
    sentence[1] = ' ';
    sentence[2] = ' ';
    sentence[3] = ' ';
    sentence[4] = ' ';
    sentence[10] = '\0';
    if (nb / 10) {
        sentence_create(nb / 10, sentence, count - 1);
    }
    sentence[count] = nb%10 + '0';
    return (sentence);
}
