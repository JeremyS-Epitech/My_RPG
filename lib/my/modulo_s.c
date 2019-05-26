/*
** EPITECH PROJECT, 2018
** modulos
** File description:
** %s
*/

#include "my.h"

void modulo_s(char s, va_list valist)
{
    if (s == 's') {
        my_putstr(va_arg(valist, char *));
    }
}
