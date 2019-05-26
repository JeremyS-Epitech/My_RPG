/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** task05
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int scan = 0;

    while (s1[i] != '\0') {
        if (s1[i] != s2[i])
            scan = 1;
        i++;
    }
    if (s2[i] != '\0')
        scan = 1;
    return (scan);
}