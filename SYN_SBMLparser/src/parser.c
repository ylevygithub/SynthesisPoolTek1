/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** main
*/

#include "../include/my.h"

t_tag *parsing_line(char *line)
{
    t_tag *tag = malloc(sizeof(t_tag));
    int i = 0;
    char *name_attribute;
    char *value;
    tag->tag = recup_tag(line, &i);
    tag->head = NULL;
    tag->next = NULL;

    while (line[i+1] != '>' && line[i] != '>') {
        name_attribute = recup_name_attribute(&i, line);
        value = recup_value_attribute(&i, line);
        tag->head = insert_attribute(tag->head, name_attribute, value);
        i++;
    }
    if (tag == NULL)
        return (NULL);
    return (tag);
}

int parsing(char **map)
{
    t_tag *tag;
    t_tag *head = NULL;

    for (int i = 1; map[i]; i++) {
        tag = parsing_line(map[i]);
        if (tag == NULL)
            return (84);
        if (tag->head != NULL && tag_exist(tag, head) == 0)
            head = insert(tag, head);
    }
    display_all(head);
    free(tag);
    return (0);
}

int open_read_and_parse(char **av)
{
    t_setmap set;

    set.pathname = av[1];
    set.fd = open(set.pathname, O_RDONLY);
    if (set.fd == -1)
        return (84);
    struct stat jack;
    stat(set.pathname, &jack);
    set.size = jack.st_size;
    set.buff = malloc(sizeof(char) * (set.size + 1));
    read(set.fd, set.buff, set.size);
    set.buff[set.size] = '\0';
    set.map = my_str_to_word_tab(set.buff);
    if (set.map == NULL)
        return (84);
    if (parsing(set.map) == 84)
        return (84);
    free(set.map);
    free(set.buff);
    return (0);
}

int open_read_and_parse_option(char **av)
{
    t_setmap set;

    set.pathname = av[1];
    set.fd = open(set.pathname, O_RDONLY);
    if (set.fd == -1)
        return (84);
    struct stat jack;
    stat(set.pathname, &jack);
    set.size = jack.st_size;
    set.buff = malloc(sizeof(char) * (set.size + 1));
    read(set.fd, set.buff, set.size);
    set.buff[set.size] = '\0';
    set.map = my_str_to_word_tab(set.buff);
    if (set.map == NULL)
        return (84);
    ID_option(set.map, av[3]);
    free(set.map);
    free(set.buff);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (open_read_and_parse(av) == 84)
            return (84);
    }
    else if (ac == 4 && av[2][0] == '-' && av[2][1] == 'i') {
        if (open_read_and_parse_option(av) == 84)
            return (84);
    }
    else
        return (84);
    return (0);
}
