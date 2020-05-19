/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** display the list
*/

#include "../include/my.h"

void display_tag(t_tag *tag)
{
    my_putstr(tag->tag);
    my_putstr("\n");
    for (t_attribute *p = tag->head; p != NULL;p = p->next) {
        my_putstr("--->");
        my_putstr(p->attribute);
        my_putstr("\n");
    }
}

void display_all(t_tag *head)
{
    t_tag *tag;

    for (tag = head; tag != NULL; tag = tag->next) {
        display_tag(tag);
    }
}

void display_value(t_attribute *head)
{
    t_attribute *p;

    for (p = head; p != NULL ; p = p->next) {
        printf("--->%s\n", p->value);
    }
}

void display_all_value(t_attribute *head)
{
    t_attribute *p;

    printf("List of species\n");
    for (p = head; p != NULL; p = p->next) {
        printf("--->%s\n", p->value);
    }
}
