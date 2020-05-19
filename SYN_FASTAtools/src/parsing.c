/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** parsing
*/

#include "../include/my.h"

char *parsing_dna(char *str , char *tmp)
{
    int i = 0;
    int x = 0;

    while (str[i] != 0 && str[i] != '>') {
        if (str[i] == 'a' || str[i] == 't' || str[i] == 'g' ||
                str[i] == 'c' || str[i] == 'n') {
            tmp[x] = str[i] - 32;
            x++;
        }
        else if (str[i] == 'A' || str[i] == 'T' || str[i] == 'G' ||
                str[i] == 'C' || str[i] == 'N') {
            tmp[x] = str[i];
            x++;
        }
        i++;
    }
    return (tmp);
}

char *parsing_identifier(char *str, char *tmp)
{
    int i = 0;
    int x = 0;

    while (str[i] != 0) {
        tmp[x] = str[i];
        i++;
        x++;
    }
    return (tmp);
}

int big_len(char *str)
{
    int len = strlen(str);
    return (len);
}

void parsing(char **map)
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
            strcpy(tmp[x], parsing_dna(map[i], tmp[x]));
        i++;
        x++;
    }
    tmp[x] = NULL;
    my_putmap(tmp);
    free(tmp);
}

int verif_fasta(char *str)
{
    int i = 0;

    while (str[i] != '.')
        i++;
    i++;
    if (str[i] == 'f' && str[i+1] == 'a' && str[i+2] == 's' &&
        str[i+3] == 't' && str[i+4] == 'a' && str[i+5] == '\0')
        return (1);
    else
        exit(84);
}
