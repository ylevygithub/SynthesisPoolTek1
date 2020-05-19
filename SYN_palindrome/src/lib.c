/*
** EPITECH PROJECT, 2019
** palindrome
** File description:
** lib.c
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;
    char *str1 = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(str1, str);

    while (str1[i] != '\0') {
        i++;
    }
    while (j < i) {
        i--;
        tmp = str1[i];
        str1[i] = str1[j];
        str1[j] = tmp;
        j++;
    }
    return (str1);
}

char *intbase_to_str(long long nb, int base)
{
    char *result;
    int size = 0;
    long long tempnb = nb;
    long long index;

    while (tempnb != 0) {
        tempnb = tempnb / base;
        size++;
    }
    result = malloc(sizeof(char) * size + 1);
    index = size;
    result[index] = '\0';
    index = size - 1;
    while (index >= 0) {
        result[index] = (nb % base) + '0';
        nb = nb / base;
        index--;
    }
    return (result);
}

char *int_to_str(long long nb)
{
    char *result;
    int size = 0;
    long long tempnb = nb;
    long long index;

    while (tempnb != 0) {
        tempnb = tempnb / 10;
        size++;
    }
    result = malloc(sizeof(char) * size + 1);
    index = size;
    result[index] = '\0';
    index = size - 1;
    while (index >= 0) {
        result[index] = (nb % 10) + '0';
        nb = nb / 10;
        index--;
    }
    return (result);
}

unsigned long str_to_int(char *str)
{
    long long number = 0;
    long long index = 0;
    long long isNeg = 0;

    if (str[0] == '-')
        isNeg = 1;
    while (str[index] >=  '0' && str[index] <= '9') {
        number += str[index] - 48;
        if (str[++index])
            number *= 10;
    }
    return (isNeg == 1 ? number *= -1 : number);
}

int is_it_number(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] > '9' || str[i] < '0')
            return (0);
    return (1);
}
