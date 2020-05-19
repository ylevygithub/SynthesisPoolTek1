/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** parsing two
*/

#include "../include/my.h"

void parsing2(char **map)
{
    int i = 0;
    int j = 0;
    char **tmp = malloc(sizeof(char*) * (map_len(map) + 2));
    int x = 0;
    int len = 0;
    int biglen;

    while (map[i] != NULL) {
        biglen = big_len(map[i]);
        tmp[x] = malloc(sizeof(char) * biglen + 1);
        if (map[i][0] == '>')
            strcpy(tmp[x], parsing_identifier(map[i], tmp[x]));
        else if (map[i][0] != '>')
            strcpy(tmp[x], parsing2_dna(map[i], tmp[x]));
        i++;
        x++;
    }
    tmp[x] = NULL;
    my_putmap(tmp);
    free(tmp);
}

char *parsing2_dna(char *str , char *tmp)
{
    int i = 0;
    int x = 0;

    while (str[i] != 0 && str[i] != '>') {
        if (str[i] == 'a' || str[i] == 'g' ||
        str[i] == 'c' || str[i] == 'n') {
            tmp[x] = str[i] - 32;
            x++;
        }
        if (str[i] == 'A' || str[i] == 'G' ||
        str[i] == 'C' || str[i] == 'N') {
            tmp[x] = str[i];
            x++;
        }
        if (str[i] == 't' || str[i] == 'T') {
            tmp[x] = 'U';
            x++;
        }
        i++;
    }
    return (tmp);
}
