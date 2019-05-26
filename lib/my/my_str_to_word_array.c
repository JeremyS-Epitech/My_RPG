/*
** EPITECH PROJECT, 2019
** my_str_to_word_arrayv2
** File description:
** better version
*/

#include "my.h"

void delete_char(char *str, int index)
{
    for (; str[index] != '\0'; index++)
        str[index] = str[index + 1];
}

char *clean_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    while (str[0] == ' ')
        delete_char(str, 0);
    while (str[my_strlen(str) - 1] == ' ')
        delete_char(str, (my_strlen(str) - 1));
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] == ' ') && (str[i + 1] == ' ')) {
            delete_char(str, i);
            i--;
        }
    return (str);
}

int count_space(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            nb++;
    return (nb);
}

char **my_str_to_word_array(char *str)
{
    int writer = 1;
    int nb = count_space(clean_str(str));
    char **tab = malloc(sizeof(char *) * (nb + 2));

    if (tab == NULL)
        return (NULL);
    tab[nb + 1] = NULL;
    tab[0] = str;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ') {
            tab[writer] = str + i + 1;
            str[i] = '\0';
            writer++;
        }
    return (tab);
}
