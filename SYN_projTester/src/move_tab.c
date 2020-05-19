/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** move tab
*/

#include "../include/my.h"

void move_tab(char **tab_files, int begin)
{
    int i = begin;

    while (tab_files[i] != NULL)
        i++;
    tab_files[i + 1] = NULL;
    while (i > begin) {
        tab_files[i] = my_strcpy(tab_files[i - 1]);
        i--;
    }
}
