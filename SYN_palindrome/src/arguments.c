/*
** EPITECH PROJECT, 2019
** palindrome
** File description:
** arguments
*/

#include "../include/my.h"

int three_arguments(char **av)
{
    if (strcmp(av[1], "-n") == 0)
        n_alone(av[2]);
    if (strcmp(av[1], "-p") == 0)
        return (0);
    return (0);
}

int five_arguments(char **av)
{
    if (is_it_number(av[2]) == 1 && strcmp(av[3], "-b") == 0 &&
    str_to_int(av[4]) == 10)
        n_alone(av[2]);
    if (is_it_number(av[2]) == 1 && strcmp(av[3], "-b") == 0 &&
        (str_to_int(av[4]) != 10))
        n_with_b(av[2], str_to_int(av[4]));
    return (0);
}

void nine_arguments(int ac, char **av)
{
    if (ac == 9) {
        if (strcmp(av[1], "-n") == 0 && is_it_number(av[2]) == 1 &&
        strcmp(av[3], "-b") == 0 && (str_to_int(av[4]) != 10) &&
        strcmp(av[5], "-imin") == 0 && strcmp(av[7], "-imax") == 0)
            n_with_maxmin(av[2], str_to_int(av[4]), str_to_int(av[6]),
            str_to_int(av[8]));
    }
}

void seven_arguments(int ac, char **av)
{
    if (strcmp(av[1], "-n") == 0 && is_it_number(av[2]) == 1 &&
    strcmp(av[3], "-b") == 0 && (str_to_int(av[4]) != 10) &&
    strcmp(av[5], "-imin") == 0)
        n_with_min(av[2], str_to_int(av[4]), str_to_int(av[6]));
    if (strcmp(av[1], "-n") == 0 && is_it_number(av[2]) == 1 &&
    strcmp(av[3], "-b") == 0 && (str_to_int(av[4]) != 10) &&
    strcmp(av[5], "-imax") == 0)
        n_with_max(av[2], str_to_int(av[4]), str_to_int(av[6]));
    if (strcmp(av[1], "-n") == 0 && is_it_number(av[2]) == 1 &&
    strcmp(av[3], "-b") == 0 && (str_to_int(av[4]) == 10) &&
    strcmp(av[5], "-imin") && is_it_number(av[6]) == 1)
        n_alone(av[2]);
    nine_arguments(ac, av);
}
