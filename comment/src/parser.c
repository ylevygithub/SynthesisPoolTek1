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
    int begin;
    int end;
    char *name_attribute;
    char *value;
    t_attribute *attribute;

    tag->tag = recup_tag(line, &i);/*recuperer tag*/
    tag->head = NULL;
    tag->next = NULL;
    while (line[i+1] != '>' && line[i] != '>') {
        name_attribute = recup_name_attribute(&i, line);/*recuperer nom de l attribut*/
        value = recup_value_attribute(&i, line);/*recuperer la valeur de l attribut*/
        /*ajout d un element a la liste chainée*/
        tag->head = insert_attribute(tag->head, name_attribute, value);
        i++;
    }
    return (tag);
}

void parsing(char **map)
{
    t_tag *tag;
    t_tag *head = NULL;
    t_attribute *attribute;
    t_attribute *head_attribute = NULL;

    for (int i = 1; map[i]; i++) {
        tag = parsing_line(map[i]);
        if (tag->head != NULL && tag_exist(tag, head) == 0)
            head = insert(tag, head);
    }
    display_all(head);
    free(tag);
}

int open_read_and_parse(int ac, char **av)
{
    int size;
    int fd;
    const char *pathname = av[1];
    char *buff;
    char **map;

    fd = open(pathname, O_RDONLY);
    struct stat jack;
    stat(pathname, &jack);
    size = jack.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    buff[size] = '\0';
    map = my_str_to_word_tab(buff);
    parsing(map);
    free(map);
    free(buff);
}

int open_read_and_parse_option(int ac, char **av)
{
    int size;
    int fd;
    const char *pathname = av[1];
    char *buff;
    char **map;
    int i;

    fd = open(pathname, O_RDONLY);
    struct stat jack;
    stat(pathname, &jack);
    size = jack.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    buff[size] = '\0';
    map = my_str_to_word_tab(buff);
    ID_option(map, av[3]);
    free(map);
    free(buff);
}

int main(int ac, char **av)
{
    if (ac == 2)
        open_read_and_parse(ac, av);
    else if (ac == 4 && av[2][0] == '-' && av[2][1] == 'i') {
        open_read_and_parse_option(ac, av);
    }
    return (0);
}
