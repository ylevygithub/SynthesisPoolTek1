/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** reactant tag for IDoption
*/

#include "../include/my.h"

char *get_value_by_name(t_tag *tag, char *attribute_name)
{
    t_attribute *p;

    for (p = tag->head; p != NULL ; p = p->next) {
        if (strcmp(p->attribute, attribute_name) == 0) {
            return (p->value);
        }
    }
    return (NULL);
}

t_attribute *recup_reactants(char **map, int *begin)
{
    int i;
    char *value;
    t_attribute *head = NULL;
    t_tag *tag;

    i = *begin;
    i++;
    tag = parsing_line(map[i]);
    while (strcmp(tag->tag, "speciesReference") == 0) {
        value = get_value_by_name(tag, "species");
        head = insert_value(head, value);
        i++;
        tag = parsing_line(map[i]);
    }
    *begin = i;
    return (head);
}

void id_reaction_reactantsAndProducts(char **map, int begin, char *value_id)
{
    int i;
    t_tag *tag;
    t_attribute *head;

    for (i = begin; map[i] != 0; i++) {
        tag = parsing_line(map[i]);
        if (strcmp(tag->tag, "listOfReactants") == 0) {
            printf("List of reactants of reaction %s\n", value_id);
            head = recup_reactants(map, &i);
            display_value(head);
        }
        else if (strcmp(tag->tag, "listOfProducts") == 0) {
            head = NULL;
            printf("List of products of reaction %s\n", value_id);
            head = recup_reactants(map, &i);
            display_value(head);
        }
    }
}
