/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** my_echo
*/

#include "../include/my.h"

void my_echo(char *chemin)
{
    DIR *dir;
    char *path = malloc(sizeof(char));
    path[0] = '\0';

    if (chemin == NULL)
        exit(0);
    dir = opendir(chemin);
    if (dir == NULL)
        exit(84);
    closedir(dir);
    print_inside_directory_for_echo(chemin, path);
    exit(0);
}
