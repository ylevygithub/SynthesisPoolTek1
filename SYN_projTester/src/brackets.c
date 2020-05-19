/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** brackets
*/

#include "../include/my.h"

char *brackets(char *path)
{
    char *tmp = malloc(strlen(path) + 4);
    int x = 0;
    int i = 0;

    tmp[x] = '[';
    x++;
    while (path[i] != 0) {
        tmp[x] = path[i];
        x++;
        i++;
    }
    tmp[x] = ']';
    tmp[x + 1] = ' ';
    tmp[x + 2] = '\0';
    return (tmp);
}
