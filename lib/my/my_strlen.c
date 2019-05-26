/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** count nb of character on a line
*/

#include "my.h"

int my_strlen_map(char const *str)
{
    static int i = 0;
    int nb = 0;

    while (str[i] != '\n') {
        i++;
        nb++;
    }
    i++;
    return (nb);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_linelen(char const *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}