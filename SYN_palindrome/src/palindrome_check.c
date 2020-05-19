/*
** EPITECH PROJECT, 2019
** palindrome
** File description:
** check if palindrome or not
*/

#include "../include/my.h"

int palindrome(char *str)
{
    char *str2 = my_revstr(str);

    if (strcmp(str, str2) == 0)
        return (1);
    else
        return (0);
}
