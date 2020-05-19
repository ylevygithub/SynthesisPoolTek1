/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** recup args for echo
*/

#include "../include/my.h"

int verif_args(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] == 'A' && str[i + 1] == 'R' && str[i + 2] == 'G' &&
        str[i + 3] == 'S')
            return (1);
        i++;
    }
    return (0);
}

char *remove_args(char *file_content)
{
    int i = 0;
    int x = 0;
    char *tmp = malloc(sizeof(char) * strlen(file_content) - 5 + 1);

    if (verif_args(file_content) == 0)
        exit(0);
    while (file_content[i] != ':')
        i++;
    i++;
    while (file_content[i] != 0) {
        tmp[x] = file_content[i];
        i++;
        x++;
    }
    tmp[x] = '\0';
    return (tmp);
}

char *recup_args_for_echo(char *file)
{
    char *buff;
    int fd = open(file, O_RDONLY);
    struct stat jack;
    size_t size;

    if (fd == -1)
        exit(84);
    stat(file, &jack);
    size = jack.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    if (read(fd, buff, size) == -1)
        exit(84);
    buff[size] = '\0';
    buff = remove_args(buff);
    return (buff);
}
