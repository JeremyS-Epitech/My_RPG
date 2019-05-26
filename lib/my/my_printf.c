/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** display all we want
*/

#include "my.h"

int my_printf(char *s, ...)
{
    int count = 0;
    va_list valist;
    int nb = my_strlen(s);

    if (nb == 0) {
        return EXIT_USAGE;
    }
    va_start(valist, s);
    while (count != nb) {
        if (s[count] == '%' && s[count + 1] != '\0') {
            count++;
            scan_flags(s[count], valist);
        } else {
            my_putchar(s[count]);
        }
        count++;
    }
    va_end(valist);
    return 0;
}
