/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** number of files
*/

#include "../include/my.h"

int number_files(char *dir_name)
{
    struct dirent *dirent;
    DIR *dir;
    int counter = 0;

    dir = opendir(dir_name);
    while ((dirent = readdir(dir)) != 0) {
        if ((dirent->d_name[0] != '.')) {
            counter++;
        }
    }
    closedir(dir);
    return (counter);
}
