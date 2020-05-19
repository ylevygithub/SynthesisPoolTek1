/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** parsing_av
*/

#include "../include/my.h"

int verif_slash(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] == '/' && str[i + 1] != '\0')
            return (1);
        i++;
    }
    if (str[i - 1] == '/')
        return (2);
    return (0);
}

char *remove_end_slash(char *str)
{
    char *tmp = malloc(sizeof(char) * strlen(str) + 1);
    int x = 0;
    int i = 0;

    while (str[i] != '/') {
        tmp[x] = str[i];
        x++;
        i++;
    }
    tmp[x] = '\0';
    return (tmp);
}

char *parsing_av(char *str)
{
    char *tmp = malloc(sizeof(char) * strlen(str) + 1);
    int x = 0;
    int i = 0;

    switch (verif_slash(str)) {
        case 0:free(tmp);return (str);break;
        case 2:str = remove_end_slash(str);return (str);break;
        default:
            break;
    }
    while (str[i] != '/')
        i++;
    i++;
    while (str[i] != '\0') {
        tmp[x] = str[i];
        x++;
        i++;
    }
    return (tmp);
}
