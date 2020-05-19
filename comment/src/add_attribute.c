/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** add attributes name and value to the list
*/

#include "../include/my.h"

t_attribute *insert_attribute(t_attribute *head, char *name, char *value)
{
    t_attribute *p_old;
    t_attribute *p;
    t_attribute *attribute = malloc(sizeof(t_attribute));
    attribute->attribute = name;
    attribute->value = value;
    if (head == NULL || strcmp(attribute->attribute, head->attribute) < 0) {
        attribute->next = head;
        head = attribute;
    } else {
        p_old = head;
        for (p = head->next; p != NULL &&
        strcmp(attribute->attribute, p->attribute) > 0; p = p->next) {
            p_old = p;
        }
        attribute->next = p;
        p_old->next = attribute;
    }
    return (head);
}
