/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** recup the name
*/

#include "../include/my.h"

char **recup_name(char **tab_files)
{
    struct dirent *dirent;
    DIR *dir;

    dir = opendir(".");
    while ((dirent = readdir(dir)) != 0) {
        if ((dirent->d_name[0] != '.')) {
            add_file(tab_files, dirent->d_name);
        }
    }
    closedir(dir);
    return (tab_files);
}
