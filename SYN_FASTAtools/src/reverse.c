/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** reverse functions
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;
    char *str1 = malloc(sizeof(char) * (strlen(str) + 1));

    strcpy(str1, str);
    while (str1[i] != '\0')
        i++;
    while (j < i) {
        i--;
        tmp = str1[i];
        str1[i] = str1[j];
        str1[j] = tmp;
        j++;
    }
    return (str1);
}

char **reverse_map(char **map)
{
    int i = 0;
    char **tmp;
    int x = 0;

    while (map[i] != NULL) {
        if (map[i][0] == '>') {
            strcpy(tmp[x], map[i]);
            i++;
            x++;
        }
        else {
            tmp[x] = my_revstr(map[i]);
            i++;
            x++;
        }
    }
    tmp[i] = NULL;
    return (tmp);
}

char *reverse_complement(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        switch (str[i])
        {
        case 'T':str[i] = 'A';i++;break;
        case 'G':str[i] = 'C';i++;break;
        case 'A':str[i] = 'T';i++;break;
        case 'C':str[i] = 'G';i++;break;
        default: str[i] = str[i]; i++;
            break;
        }
    }
    return (str);
}
