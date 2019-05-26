/*
** EPITECH PROJECT, 2018
** my
** File description:
** my_putstr_error
*/

#include "my.h"

int my_putstr_error(const char *str)
{
    int check_write = 0;

    for (int count = 0; str[count] != '\0'; count++) {
        check_write = write(2, &str[count], 1);
    }
    return (check_write);
}
