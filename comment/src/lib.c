/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** lib functions
*/

#include "../include/my.h"

void  my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb++;
    }
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int my_char_isalphamin(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    else
        return (0);
}

void my_putmap(char **map)
{
    int i = 0;

    while (map[i]) {
        write(1, map[i], my_strlen(map[i]));
        my_putchar('\n');
        i++;
    }
}
