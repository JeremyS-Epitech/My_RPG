/*
** EPITECH PROJECT, 2018
** my
** File description:
** my_memset
*/

#include "my.h"

char **my_memset(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int count = 0; map[i][count] != '\0'; count++)
            map[i][count] = '\0';
    }
    return (map);
}

char *my_str_memset(char *str, int c, size_t n)
{
    int size = n;

    for (int i = 0; i != size; i++) {
        str[i] = c;
    }
    return (str);
}