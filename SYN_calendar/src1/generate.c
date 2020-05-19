/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** fill
*/

#include "../include/my.h"

char *finalize(char *str)
{
    int x = 0;
    int nbr = count_nbr_caract(str);
    char *tmp = malloc(sizeof(char) * (nbr + 1));

    tmp = parsing_dna(str, tmp);
    return (tmp);
}

char **generate_lastline(t_generate gen, char **map, char **tmp)
{
    tmp[gen.itmp] = finalize(gen.total);
    free(gen.total);
    gen.itmp++;
    tmp[gen.itmp] = NULL;
    return (tmp);
}

char *fill_dna(t_generate gen, char **map, char **tmp)
{
    if (gen.total == NULL)
        gen.total = finalize(map[gen.imap]);
    else
        gen.total = my_realloc(gen.total, map[gen.imap]);
    return (gen.total);
}

char *generate_lines_from_second(t_generate gen, char **map)
{
    char *tmp;

    if (gen.imap != 0) {
        tmp = my_strcpy(gen.total);
        free(gen.total);
        gen.itmp++;
    }
    return (tmp);
}

char **generate_tmp(char **map)
{
    t_generate gen;
    gen.total = NULL;
    gen.itmp = 0;

    int nbr = count_nbr_greater(map);
    char **tmp = malloc(sizeof(char*) * (nbr*2+1));
    for (gen.imap = 0; map[gen.imap]; gen.imap++) {
        if (map[gen.imap][0] == '>') {
            ((tmp[gen.itmp] = generate_lines_from_second(gen, map)) != NULL) ?
            gen.itmp++ : 1;
            tmp[gen.itmp] = my_strcpy(map[gen.imap]);
            gen.itmp++;
            gen.total = NULL;;
        } else
            gen.total = fill_dna(gen, map, tmp);
    }
    tmp = generate_lastline(gen, map, tmp);
    return (tmp);
}
