/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** lib
*/

#include "../include/my.h"

char *my_strcpy(char *str)
{
    int i = 0;
    char *result = malloc(sizeof(char) * strlen(str) + 1);

    while (str[i]) {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}

int verif_dot(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] == '.')
            return (1);
        i++;
    }
    return (0);
}

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

char *my_realloc(char *first, char *second)
{
    int i = 0;
    int x = 0;
    int len = strlen(first) + strlen(second);
    char *str = malloc(sizeof(char) * len + 1);

    while (first[i] != 0) {
        str[i] = first[i];
        i++;
    }
    while (second[x] != 0) {
        str[i] = second[x];
        i++;
        x++;
    }
    free(first);
    str[i] = '\0';
    return (str);
}
