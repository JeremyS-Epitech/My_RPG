/*
** EPITECH PROJECT, 2019
** my
** File description:
** my_str_low_case
*/

#include "my.h"

int my_str_low_case(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' && str[i] > 'z')
            return (1);
    }
    return (0);
}
