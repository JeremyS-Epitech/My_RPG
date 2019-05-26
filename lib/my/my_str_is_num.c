/*
** EPITECH PROJECT, 2019
** my
** File description:
** my_str_is_num_c
*/

#include "my.h"

int my_str_is_num(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}

int my_line_is_num(char const *str)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}