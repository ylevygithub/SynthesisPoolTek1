/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** remove tdf
*/

#include "../include/my.h"

char *remove_tdf(char *str)
{
    char *tmp = malloc(sizeof(char) * strlen(str) + 3);
    int x = 0;
    int i = 0;

    while (str[i] != '.') {
        tmp[x] = str[i];
        x++;
        i++;
    }
    tmp[x] = '\0';
    return (tmp);
}
