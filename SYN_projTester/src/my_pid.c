/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** my fork
*/

#include "../include/my.h"

int my_pid(char *concat_path_cmd, char **cmd, char **my_env)
{
    pid_t pid = fork();

    if (pid < 0)
        write(2,"Error to execute ps\n", 20);
    if (pid > 0)
        wait(NULL);
    if (pid == 0) {
        if (execve(concat_path_cmd, cmd, my_env) == -1)
            return (84);
    }
    return (0);
}
