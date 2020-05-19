/*
** EPITECH PROJECT, 2019
** projTester
** File description:
** requirement
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>

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

char *my_strcpy(char *str)
{
    int i = 0;
    char *result = malloc(sizeof(char) * strlen(str) + 1);

    while (str[i]) {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}

void my_ps_synthesis(void)
{
    char **cmd = malloc(sizeof(char*) * 2);

    cmd[0] = my_strcpy("ps");
    cmd[1] = NULL;
    if (my_pid("/usr/bin/ps", cmd, NULL) == 84)
        my_pid("/bin/ps", cmd, NULL);
}
