/*
** EPITECH PROJECT, 2018
** fs_read_map
** File description:
** read map
*/

#include "rpg.h"

rpg_t extract_map(rpg_t rpg)
{
    rpg.map.map = malloc(sizeof(*rpg.map.map));
    return (rpg);
}

int get_the_number_of_line(char *arg)
{
    char *buff = NULL;
    size_t size = 0;
    int nb_of_line = 0;
    FILE *fp = fopen(arg, "r");
    int check_getline = 0;

    if (fp == NULL)
        return (0);
    while (check_getline != -1) {
        check_getline = getline(&buff, &size, fp);
        if (check_getline == -1)
            return (nb_of_line);
        nb_of_line++;
    }
    fclose(fp);
    return (nb_of_line);
}

rpg_t init_map(rpg_t rpg)
{
    rpg.map.map = malloc(sizeof(*rpg.map.map) * (rpg.map.lenght + 1));
    rpg.map.map[rpg.map.lenght] = NULL;
    rpg.map.map = my_memset(rpg.map.map);
    return (rpg);
}

rpg_t fs_read_map(char *arg, rpg_t rpg)
{
    char *buff = NULL;
    size_t size = 0;
    FILE *fp = fopen(arg, "r");
    int check_getline = 0;
    int i = 0;

    rpg.map.lenght = get_the_number_of_line(arg);
    rpg = init_map(rpg);
    if (rpg.map.lenght == 0 || fp == NULL)
        return (rpg);
    while (check_getline != -1) {
        check_getline = getline(&buff, &size, fp);
        rpg.map.map[i] = malloc(sizeof(*rpg.map.map) * (my_strlen(buff) + 1));
        rpg.map.map[i] = my_str_memset(rpg.map.map[i], '\0', my_strlen(buff));
        for (int j = 0; buff[j]; j++)
            rpg.map.map[i][j] = buff[j];
        i++;
    }
    fclose(fp);
    return (rpg);
}
