/*
** EPITECH PROJECT, 2018
** moduloc
** File description:
** %c
*/

#include "my.h"

void modulo_c(char s, va_list valist)
{
    if (s == 'c') {
        my_putchar(va_arg(valist, int));
    }
}
