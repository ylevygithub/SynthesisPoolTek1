/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** lib
*/

#include "../include/my.h"

int end_verif(char **map)
{
    int i;

    for (i = 0;map[i] != NULL;i++);
    if (strcmp(map[i-1], "END") != 0)
        exit (84);
}

int wordlen(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != ' ') {
        i++;
    }
    return (i);
}

int str_to_int(char *str)
{
    int number = 0;
    int index = 0;
    int isNeg = 0;

    if (str[0] == '-')
        isNeg = 1;
    while (str[index] >=  '0' && str[index] <= '9') {
        number += str[index] - 48;
        if (str[++index])
            number *= 10;
    }
    return (isNeg == 1 ? number *= -1 : number);
}

void swap(int *a, int*b) 
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
