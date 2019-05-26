/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** main
*/

#include "rpg.h"

void h_dash(void)
{
    my_putstr("RPG created with CSFML.\n\n");
    my_putstr("USAGE\n");
    my_putstr("     ./my_rpg\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("-help         print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("              - Arrow key to move the character.\n");
    my_putstr("              - Mouse to interact with the button.\n");
}

int is_usage_or_error(int ac, char **av)
{
    if (ac > 2)
        return (1);
    if (ac == 2) {
        if (my_strcmp(av[1], "-help\0") == 0) {
            h_dash();
            return (2);
        } else {
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    int check_usage_or_error = is_usage_or_error(ac, av);

    if (check_usage_or_error == 1) {
        my_putstr_error("./my_rpg: no argument is required\n");
        my_putstr_error("retry with -help\n");
        return (84);
    }
    if (check_usage_or_error == 2)
        return (0);
    if (open_window(av[1]) != 0)
        return (EXIT_ERROR);
    return (EXIT_SUCCESS);
}
