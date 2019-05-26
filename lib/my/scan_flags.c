/*
** EPITECH PROJECT, 2018
** flags
** File description:
** many flags
*/

#include "my.h"

void scan_flags(char s, va_list valist)
{
    modulo_s(s, valist);
    modulo_c(s, valist);
    modulo_i(s, valist);
    modulo_mod(s);
    modulo_u(s, valist);
    modulo_o(s, valist);
}
