/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** lib
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb = nb + 1;
    }
}

char **newline(char **map, int *pti)
{
    int i = *pti;

    if (map[i + 1] && map[i + 1][0] == '>') {
        my_putchar('\n');
    }
    *pti = i;
    return (map);
}

void my_putmap(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i]) {
        while (map[i] && map[i][j] != '>') {
            write(1, map[i], strlen(map[i]));
            map = newline(map, &i);
            i++;
        }
        if (map[i] && map[i][j] == '>') {
            write(1, map[i], strlen(map[i]));
            my_putchar('\n');
            i++;
        }
    }
    my_putchar('\n');
}

int is_it_number(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] > '9' || str[i] < '0')
                return (0);
    return (1);
}
