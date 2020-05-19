/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** add file in tab
*/

#include "../include/my.h"

void add_file(char **tab_files, char *file_name)
{
    int i = 0;

    while (tab_files[i] != NULL && strcmp(file_name, tab_files[i]) > 0)
        i++;
    if (tab_files[i] == NULL) {
        tab_files[i] = malloc(sizeof(char) * (strlen(file_name) + 1));
        strcpy(tab_files[i], file_name);
        tab_files[i + 1] = NULL;
    } else {
        move_tab(tab_files, i);
        tab_files[i] = malloc(sizeof(char) * (strlen(file_name) + 1));
        strcpy(tab_files[i], file_name);
    }
}
