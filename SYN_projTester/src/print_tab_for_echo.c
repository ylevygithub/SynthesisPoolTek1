/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** print tab for echo
*/

#include "../include/my.h"

void print_tab_for_echo(char **tab_files, char *path)
{
    int i = 0;
    char *path2;

    while (tab_files[i]) {
        if (opendir(tab_files[i]) != NULL) {
            path2 = my_strcpy(path);
            path2 = my_realloc(path2, brackets(tab_files[i]));
        }
        else
            printf("%s%s: %s\n", path, remove_tdf(tab_files[i]),
            recup_args_for_echo(tab_files[i]));
        print_inside_directory_for_echo(tab_files[i], path2);
        i++;
    }
}
