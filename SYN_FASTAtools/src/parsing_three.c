/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** parsing three
*/

#include "../include/my.h"

char **change_letters(char **map)
{
    int i = 0;
    char **tmp;
    int x = 0;

    while (map[i] != NULL) {
        if (i % 2 == 0) {
            strcpy(tmp[x], map[i]);
        }
        if (i % 2 != 0) {
            tmp[x] = reverse_complement(map[i]);
        }
        i++;
        x++;
    }
    tmp[x] = NULL;
    return (tmp);
}

void parsing3(char **map)
{
    char **tmp = generate_tmp(map);
    tmp = reverse_map(tmp);
    tmp = change_letters(tmp);
    putmap(tmp);
}