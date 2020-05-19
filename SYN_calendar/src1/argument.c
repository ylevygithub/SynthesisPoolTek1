/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** arguments
*/

#include "../include/my.h"

void argument_nbr(char **av)
{
    (strcmp(av[1], "1") == 0) ? read_and_parse_one(av) : 1;
    (strcmp(av[1], "2") == 0) ? read_and_parse_two(av) : 1;
    (strcmp(av[1], "3") == 0) ? read_and_parse_three(av) : 1;
    ((strcmp(av[1], "4") == 0) && is_it_number(av[2]) == 1) ?
    read_and_parse_four(av, str_to_int(av[2])) : 1;
    (strcmp(av[1], "5") == 0) ? read_and_parse_three(av) : 1;
    (strcmp(av[1], "6") == 0) ? read_and_parse_three(av) : 1;
    (strcmp(av[1], "7") == 0) ? read_and_parse_three(av) : 1;
    exit(84);
}

void arguments(int ac, char **av)
{
    if (ac == 2 && is_it_number(av[1]) == 1)
        argument_nbr(av);
    else if (ac == 2)
        open_read(av);
    else
        exit(84);
}
