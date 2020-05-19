/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** recuperation of tags, attributes and values
*/

#include "../include/my.h"

char *recup(int begin, int end, char *line)
{
    int len = end - begin + 1;
    char *tmp = malloc(sizeof(char) * len + 1);
    int i = 0;

    while (begin <= end) {
        tmp[i] = line[begin];
        i++;
        begin++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char *recup_tag(char *line, int *pti)
{
    int begin;
    int end;
    char *tag;
    int i = *pti;

    while (my_char_isalphamin(line[i]) != 1)
        i++;
    begin = i;
    while (line[i] != ' ' && line[i] != '>')
        i++;
    end = i - 1;
    tag = recup(begin, end, line);
    *pti = i;
    return (tag);
}

char *recup_name_attribute(int *pti, char *line)
{
    int begin;
    int end;
    char *name_attribute;
    int i = *pti;

    i++;
    begin = i;
    while (line[i] != '=')
        i++;
    end = i - 1;
    name_attribute = recup(begin, end, line);
    *pti = i;
    return (name_attribute);
}

char *recup_value_attribute(int *pti, char *line)
{
    int i = *pti;
    int begin;
    int end;
    char *value;

    i = i + 2;
    begin = i;
    while (line[i] != '"')
        i++;
    end = i - 1;
    value = recup(begin, end, line);
    *pti = i;
    return (value);
}
