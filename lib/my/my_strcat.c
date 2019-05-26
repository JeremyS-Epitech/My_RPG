/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** add something at the beginning of the string
*/

#include "my.h"

char *my_str_memset(char *str, int c, size_t n)
{
    int size = n;

    for (int i = 0; i != size; i++) {
        str[i] = c;
    }
    return (str);
}

char *fill_in_map(char *stock, char *dest, int i)
{
    for (int y = 0; dest[y - 1] != '\n'; y++) {
        stock[i] = dest[y];
        i++;
    }
    return (stock);
}

char *my_strcat(char *dest, char *src)
{
    int len_src = 0;
    int len_dest = my_linelen(dest) + 1;
    int i = 0;
    char *stock = NULL;

    if (src == NULL) {
        stock = malloc(sizeof(char) * (len_dest + 1));
        stock = my_str_memset(stock, '\0', len_dest + 1);
    } else {
        len_src = my_strlen(src);
        stock = malloc(sizeof(char) * (len_src + len_dest + 1));
        stock = my_str_memset(stock, '\0', len_src + len_dest + 1);
        while (src[i] != '\0') {
            stock[i] = src[i];
            i++;
        }
    }
    stock = fill_in_map(stock, dest, i);
    return (stock);
}
