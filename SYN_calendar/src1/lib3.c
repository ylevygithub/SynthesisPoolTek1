/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** lib3 functions
*/

#include "../include/my.h"

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
