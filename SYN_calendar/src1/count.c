/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** count
*/

#include "../include/my.h"

int count_nbr_greater(char **map)
{
    int i = 0;
    int counter = 0;

    while (map[i] != NULL) {
        if (map[i][0] == '>')
            counter++;
        i++;
    }
    return (counter);
}

int count_nbr_caract(char *str)
{
    int i = 0;

    while (str[i] != '>' && str[i] != '\0')
        i++;
    return (i);
}
