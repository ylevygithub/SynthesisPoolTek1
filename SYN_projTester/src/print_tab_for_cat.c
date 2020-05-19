/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** print_tab_for_cat
*/

#include "../include/my.h"

char **recup_for_cat2(char **tab, char **cmd)
{
    cmd[0] = my_strcpy("cat");
    cmd[1] = tab[0];
    cmd[2] = tab[1];
    cmd[3] = NULL;
    return (cmd);
}

void execute_cat(char **cmd)
{
    if (my_pid("/usr/bin/cat", cmd, NULL) == 84)
        my_pid("/bin/cat", cmd, NULL);
    else
        my_putstr("\n");
    exit(0);
}

void print_tab_for_cat(char **tab_files, char *path)
{
    char *path2;
    char **cmd = malloc(sizeof(char*) * 4);
    char **tab;

    for (int i = 0; tab_files[i]; i++) {
        if (opendir(tab_files[i]) != NULL) {
            path2 = my_strcpy(path);
            path2 = my_realloc(path2, brackets(tab_files[i]));
        }
        else if (verif_dot(tab_files[i]) == 1) {
            my_putstr(path);
            my_putstr(remove_tdf(tab_files[i]));
            my_putstr(": ");
            tab = recup_args_for_cat(tab_files[i]);
            tab = recup_for_cat2(tab, cmd);
            execute_cat(cmd);
        }
        print_inside_directory_for_cat(tab_files[i], path2);
    }
}
