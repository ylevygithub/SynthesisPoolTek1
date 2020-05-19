/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** open read
*/

#include "../include/my.h"

int read_and_parse_four(char **av, int kmers)
{
    t_setmap set;
    size_t len = 0;

    set.buff = get_map(len);
    set.map = my_str_to_word_tab(set.buff);
    parsing4(set.map, kmers);
    if (set.buff == NULL)
        exit(84);
    free(set.buff);
    free(set.map);
    exit(0);
}

int read_and_parse_three(char **av)
{
    t_setmap set;
    size_t len = 0;

    set.buff = get_map(len);
    set.map = my_str_to_word_tab(set.buff);
    parsing3(set.map);
    if (set.buff == NULL)
        exit(84);
    free(set.buff);
    free(set.map);
    exit(0);
}

int read_and_parse_two(char **av)
{
    t_setmap set;
    size_t len = 0;

    set.buff = get_map(len);
    set.map = my_str_to_word_tab(set.buff);
    parsing2(set.map);
    if (set.buff == NULL)
        exit(84);
    free(set.buff);
    free(set.map);
    exit(0);
}

int read_and_parse_one(char **av)
{
    t_setmap set;
    size_t len = 0;

    set.buff = get_map(len);
    set.map = my_str_to_word_tab(set.buff);
    parsing(set.map);
    if (set.buff == NULL)
        exit(84);
    free(set.buff);
    free(set.map);
    exit(0);
}

int open_read(char **av)
{
    t_setmap set;

    verif_fasta(av[1]);
    set.pathname = av[1];
    set.fd = open(set.pathname, O_RDONLY);
    if (set.fd == -1)
        exit(84);
    struct stat jack;
    stat(set.pathname, &jack);
    set.size = jack.st_size;
    set.buff = malloc(sizeof(char) * (set.size + 1));
    read(set.fd, set.buff, set.size);
    set.buff[set.size] = '\0';
    my_putstr(set.buff);
    if (set.buff == NULL)
        exit(84);
    free(set.buff);
    exit(0);
}
