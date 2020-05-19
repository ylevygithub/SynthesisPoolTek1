/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** ID option
*/

#include "../include/my.h"

char *recup_value(t_tag *tag, char *attribute_name)
{
    t_attribute *p;

    for (p = tag->head; p != NULL ; p = p->next) {
        if (strcmp(p->attribute, attribute_name) == 0) {
            return (p->value);
        }
    }
    return (NULL);
}

t_attribute *insert_value(t_attribute *head, char *value)
{
    t_attribute *p;
    t_attribute *p_old;
    t_attribute *attribute = malloc(sizeof(t_attribute));
    attribute->value = value;

    if (head == NULL || strcmp(attribute->value, head->value) < 0) {
        attribute->next = head;
        head = attribute;
    } else {
        p_old = head;
        for (p = head->next; p != NULL &&
        strcmp(attribute->value, p->value) > 0; p = p->next) {
            p_old = p;
        }
        attribute->next = p;
        p_old->next = attribute;
    }
    return (head);
}

t_attribute *all_chemicalProducts(t_tag *tag,
t_attribute *head, char *value_id)
{
    char *value;

    if (verifying_if_keyword_isfound(value_id, "compartment", tag) == 0) {
        value = recup_value(tag, "name");
        head = insert_value(head, value);
    }
    return (head);
}

void id_not_found(char **map, int begin, char *value_id)
{
    int i;
    t_tag *tag;
    t_attribute *head = NULL;

    for (i = begin; map[i] != 0; i++) {
        tag = parsing_line(map[i]);
        if (strcmp(tag->tag, "species") == 0) {
            head = all_chemicalProducts(tag,
            head, value_id);
        }
    }
    display_all_value(head);
}
