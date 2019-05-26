/*
** EPITECH PROJECT, 2018
** my_atoi.c
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char const *str)
{
    int res = 0;
    int i = 0;

    if (str[0] == '-')
        i++;
    while (str[i] != '\0') {
        res = res * 10 + str[i] - '0';
        i++;
    }
    if (str[0] == '-')
        res = (-res);
    return (res);
}

int my_line_atoi(char const *str)
{
    int res = 0;
    int i = 0;

    if (str[0] == '-')
        i++;
    while (str[i] != '\n') {
        res = res * 10 + str[i] - '0';
        i++;
    }
    if (str[0] == '-')
        res = (-res);
    return (res);
}