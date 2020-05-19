/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** lib2
*/

#include "../include/my.h"

int map_len(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        i++;
    }
    return (i);
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

char *get_map(size_t len)
{
    int i = 0;
    char *str;
    char *result;
    char *file_str;

    getline(&str, &len, stdin);
    result = my_strcpy(str);
    while (getline(&str, &len, stdin) > 0) {
        if (i % 2 == 0)
            file_str = my_realloc(result, str);
        else
            result = my_realloc(file_str, str);
        i++;
    }
    if (i % 2 == 0)
        return (result);
    return (file_str);
}

char *my_strcpy(char *str)
{
    int i = 0;
    char *res = malloc(sizeof(char) * strlen(str) + 1);

    while (str[i]) {
        res[i] = str[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

void putmap(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        my_putstr(map[i]);
        my_putchar('\n');
        i++;
    }
}
