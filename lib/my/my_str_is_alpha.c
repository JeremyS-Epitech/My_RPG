/*
** EPITECH PROJECT, 2019
** my
** File description:
** my_str_is_alpha
*/

#include "my.h"

int my_str_is_alpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z')
            && (str[i] < 'A' || str[i] > 'Z'))
            return (1);
    }
    return (0);
}
