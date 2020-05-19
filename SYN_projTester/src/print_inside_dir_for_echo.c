/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** print inside dir for echo
*/

#include "../include/my.h"

void print_inside_directory_for_echo(char *dir_name, char *path)
{
    char **tab_files;
    int nbr;

    if (chdir(dir_name) == -1)
        return;
    nbr = number_files(".");
    tab_files = malloc(sizeof(char *) * (nbr + 1));
    tab_files[0] = NULL;
    tab_files = recup_name(tab_files);
    print_tab_for_echo(tab_files, path);
    chdir("..");
}
