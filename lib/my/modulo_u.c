/*
** EPITECH PROJECT, 2018
** modulo_u
** File description:
** %u
*/

#include "my.h"

void modulo_u(char s, va_list valist)
{
    if (s == 'u') {
        my_put_nbr(va_arg(valist, unsigned int));
    }
}
