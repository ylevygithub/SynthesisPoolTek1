/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** str_to_word_tab
*/

#include "../include/my.h"

int char_verif(char c)
{
    if (c == '\n')
        return (0);
    return (1);
}

int my_count(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0'){
        if (char_verif(str[i]) == 1 &&
            char_verif(str[i + 1]) != 1) {
            count++;
        }
        i++;
    }
    return (count);
}

int my_wordlen(char *str, int i)
{
    while (str[i] != '\0') {
        if (char_verif(str[i]) != 1)
            return (i);
        i++;
    }
    return (i);
}

char **my_str_to_word_tab(char *str)
{
    int x = 0;
    int count = my_count(str) + 1;
    char **map = malloc(sizeof(char *) * (count + 1));
    int j = 0;

    for (int i = 0; i < count; i++) {
        j = 0;
        while  (str[x] && char_verif(str[x]) != 1)
            x++;
        map[i] = malloc(sizeof(char) * my_wordlen(str, x) + 2);
        while (str[x] != '\0' && char_verif(str[x]) != 0) {
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
