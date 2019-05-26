/*
** EPITECH PROJECT, 2018
** my
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(const char *str)
{
    int check_write = 0;

    for (int count = 0; str[count] != '\0'; count ++)
        check_write = write(1, &str[count], 1);
    return (check_write);
}
