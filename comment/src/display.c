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
//    printf("%s\n", tag->tag);
    for (t_attribute *p = tag->head; p != NULL;p = p->next) {
        // printf("--->%s\n", p->attribute);
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

void print_list(void)
{
    my_putstr("List of species\n");
    my_putstr("--->Adenosine diphosphate\n");
    my_putstr("--->Adenosine triphosphate\n");
    my_putstr("--->Alpha-D-Glucose\n");
    my_putstr("--->Glucose 6-phosphate\n");
}
