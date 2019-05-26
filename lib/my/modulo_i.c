/*
** EPITECH PROJECT, 2018
** moduloid
** File description:
** %i
*/

#include "my.h"

void modulo_i(char s, va_list valist)
{
    if (s == 'i' || s == 'd') {
        my_put_nbr(va_arg(valist, int));
    }
}
