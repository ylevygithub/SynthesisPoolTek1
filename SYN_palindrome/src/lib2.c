/*
** EPITECH PROJECT, 2019
** palindrome
** File description:
** lib2.c
*/

#include "../include/my.h"

int my_compute_power_it(int nb, int p)
{
    int i = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    while (p > 1) {
        nb *= i;
        p--;
    }
    return (nb);
}

unsigned long convert_base_res_in_initial_base(char *str, int base)
{
    int i = strlen(str) - 1;
    unsigned long save = 0;

    for (int counter = 0; i >= 0; counter ++) {
        save = save + ((str[i] - '0') * my_compute_power_it(base, counter));
        i--;
    }
    return (save);
}

int index_pair_is_not_nbr(char **av)
{
    int i = 2;

    while (av[i] != NULL) {
        if (i % 2 == 0 && is_it_number(av[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}
