/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** recup for cat
*/

#include "../include/my.h"

char *remove_args_for_cat(char *file_content)
{
    int i = 0;
    int x = 0;
    char *tmp = malloc(sizeof(char) * strlen(file_content) - 5 + 1);

    while (file_content[i - 1] != 'S' && file_content[i] != ':')
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

char *recup_input(char *file_content)
{
    int i = 0;
    int x = 0;
    char *tmp = malloc(sizeof(char) * strlen(file_content) - 6 + 1);

    while (file_content[i - 1] != 'T' && file_content[i] != ':')
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

char **recup_args_for_cat(char *file)
{
    char *buff;
    char **tab;
    int fd = open(file, O_RDONLY);
    struct stat jack;
    size_t size;

    if (fd == -1)
        exit (84);
    stat(file, &jack);
    size = jack.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    if (read(fd, buff, size) == -1)
        exit(84);
    buff[size] = '\0';
    tab = my_str_to_word_tab(buff);
    tab[0] = remove_args_for_cat(tab[0]);
    tab[1] = recup_input(tab[1]);
    tab[2] = NULL;
    return (tab);
}
