/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** print the tab
*/

#include "../include/my.h"

void print_tab(char **tab_files, int level)
{
    int i = 0;

    while (tab_files[i]) {
        for (int j = 1;j <= level; j++) {
            printf("-----");
        }
        printf("%s\n", tab_files[i]);
        print_inside_directory(tab_files[i], level+1);
        i++;
    }
}
