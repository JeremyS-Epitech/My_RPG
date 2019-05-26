/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** include an function declaration
*/

#ifndef _MY_H_
#define _MY_H_

#define EXIT_USAGE 84
#define EXIT_SUCCESS 0

#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_putchar(char c);
char *my_str_memset(char *str, int c, size_t n);
void scan_flags(char s, va_list valist);
void modulo_s(char s, va_list valist);
void modulo_c(char s, va_list valist);
void modulo_i(char s, va_list valist);
void modulo_mod(char s);
void modulo_u(char s, va_list valist);
void modulo_o(char s, va_list valist);
void my_print_array(char **input);
int my_atoi(char const *str);
int my_printf(char *s, ...);
int my_strlen(char const *str);
int my_linelen(char const *str);
int my_putstr(const char *str);
int my_put_nbr(int nb);
int my_str_low_case(char const *str);
int my_str_upp_case(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strstr(char *str, const char *to_find);
int my_linestr(char *str, const char *to_find);
int my_str_is_alpha(char const *str);
int my_str_is_num(char const *str);
int my_line_is_num(char const *str);
char **my_memset(char **map);
char *my_strcat(char *dest, char *src);
int my_line_atoi(char const *str);
int my_putstr_error(const char *str);
char **my_str_to_word_arrau(char *str);

#endif
