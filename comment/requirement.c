/*
** EPITECH PROJECT, 2019
** SBML parser
** File description:
** my_strtowordtab_synthesis
*/

#include "include/my.h"

int char_verification(char c)
{
    if ((c < '0') || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') ||
    (c > 'z'))
        return (0);
    return (1);
}

int counter(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0'){
        if (char_verification(str[i]) == 1 &&
            char_verification(str[i + 1]) != 1) {
            count++;
        }
        i++;
    }
    return (count);
}

int wordlen(char const *str, int i)
{
    while (str[i] != '\0') {
        if (char_verification(str[i]) != 1)
            return (i);
        i++;
    }
    return (i);
}

char **my_str_to_word_array_synthesis(char const *str)
{
    int x = 0;
    int count = counter(str) + 1;
    char **map = malloc(sizeof(char *) * (count + 1));
    int j = 0;

    for (int i = 0; i < count; i++) {
        j = 0;
        while  (str[x] && char_verification(str[x]) != 1)
            x++;
        map[i] = malloc(sizeof(char) * wordlen(str, x) + 2);
        while (str[x] != '\0' && char_verification(str[x]) != 0) {
            map[i][j] = str[x];
            j++;
            x++;
        }
        map[i][j] = '\0';
        x++;
    }
    map[count - 1] = NULL;
    return (map);
}
