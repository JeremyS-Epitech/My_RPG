/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** find a char * inside a char *
*/

#include "my.h"

int my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int length = my_linelen(to_find) + 1;

    while (str[i] != '\0') {
        while (str[i + j] == to_find[j])
            j++;
        if (j == length)
            return (1);
        i++;
        j = 0;
    }
    return (0);
}

int my_linestr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int length = my_linelen(to_find) + 1;

    while (str[i] != '\n') {
        while (str[i + j] == to_find[j])
            j++;
        if (j == length)
            return (1);
        i++;
        j = 0;
    }
    return (0);
}
