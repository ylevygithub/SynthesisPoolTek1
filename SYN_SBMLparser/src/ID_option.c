/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** ID option
*/

#include "../include/my.h"

int check_same_value(t_attribute *p, char *value_id)
{
    if (strcmp(p->value, value_id) == 0) {
        return (1);
    }
    return (0);
}

int verifying_if_keyword_isfound(char *value_id,
char *attribute_name, t_tag *tag)
{
    int verif;
    t_attribute *p;

    for (p = tag->head; p != NULL ; p = p->next) {
        if (strcmp(p->attribute, attribute_name) == 0)
            verif = check_same_value(p, value_id);
    }
    if (verif == 1)
        return (1);
    return (0);
}

t_attribute *id_compartment_chemicalProducts2(t_tag *tag,
t_attribute *head, char *value_id)
{
    char *value;

    if (verifying_if_keyword_isfound(value_id, "compartment", tag) == 1) {
        value = recup_value(tag, "name");
        head = insert_value(head, value);
    }
    return (head);
}

void id_compartment_chemicalProducts(char **map, int begin, char *value_id)
{
    int i;
    t_tag *tag;
    t_attribute *head = NULL;

    for (i = begin; map[i] != 0; i++) {
        tag = parsing_line(map[i]);
        if (strcmp(tag->tag, "species") == 0) {
            head = id_compartment_chemicalProducts2(tag,
            head, value_id);
        }
    }
    printf("List of species in compartment %s\n", value_id);
    display_value(head);
}

void ID_option(char **map, char *value_id)
{
    int i;
    int found = 0;
    t_tag *tag;

    for (i = 0; map[i] != 0 && found == 0; i++) {
        tag = parsing_line(map[i]);
        found = verifying_if_keyword_isfound(value_id, "id", tag);
    }
    if (found == 1) {
        if (strcmp(tag->tag, "compartment") == 0)
            id_compartment_chemicalProducts(map, i, value_id);
        else if (strcmp(tag->tag, "reaction") == 0)
            id_reaction_reactantsAndProducts(map, i, value_id);
    }
    else
        id_not_found(map, 1, value_id);
}
