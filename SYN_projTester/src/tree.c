/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** tree
*/

#include "../include/my.h"

void my_tree(char *path)
{
    DIR *dir;

    if (path == NULL)
        exit(0);
    dir = opendir(path);
    if (dir == NULL)
        exit(84);
    closedir(dir);
    printf("%s\n", parsing_av(path));
    print_inside_directory(path, 1);
}
