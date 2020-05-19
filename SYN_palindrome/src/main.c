/*
** EPITECH PROJECT, 2019
** palindrome
** File description:
** main
*/

#include "../include/my.h"

void error_management(int ac, char **av)
{
    int imin = str_to_int(av[6]);
    int imax = str_to_int(av[8]);

    if ((ac < 3 || ac > 9) || (ac % 2 == 0) || ((strcmp(av[1], "-n") != 0 &&
    strcmp(av[1], "-p") != 0)) || (index_pair_is_not_nbr(av) == 1) ||
    ac > 3 && (strcmp(av[3], "-b") == 0 && (1 >= str_to_int(av[4]) ||
    str_to_int(av[4]) > 10)) || ac > 5 && ((0 > str_to_int(av[6]) ||
    str_to_int(av[6]) > 100)) || (ac > 3 && strcmp(av[3], "-b") != 0) ||
    ac > 5 && ((strcmp(av[5], "-imin") != 0 &&
    (strcmp(av[5], "-imax") != 0))) || ac > 7 &&
    ((strcmp(av[5], "-imin") == 0 && (strcmp(av[7], "-imax") == 0))) &&
    imin > imax) {
        write(2, "invalid argument\n", 17);
        exit(84);
    }
    if (ac >= 3 && strcmp(av[1], "-p") == 0 && palindrome(av[2]) == 0) {
        write(2, "invalid argument\n", 17);
        exit(84);
    }
}

int main(int ac, char **av)
{
    error_management(ac, av);
    if (ac > 5)
        seven_arguments(ac, av);
    if (ac == 3)
        three_arguments(av);
    if (ac == 5)
        five_arguments(av);
    return (0);
}
