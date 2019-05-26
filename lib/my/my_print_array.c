/*
** EPITECH PROJECT, 2018
** my
** File description:
** my_print_array
*/

#include "my.h"

void my_print_array(char **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++)
            my_printf("%c", map[y][x]);
    }
}
