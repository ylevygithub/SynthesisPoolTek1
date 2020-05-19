/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** verifying if its bigger or smaller than, to have an alphabetical order
*/

#include "../include/my.h"

t_tag *insert(t_tag *tag, t_tag *head)
{
    t_tag *p_old;
    t_tag *p;

    if (head == NULL || strcmp(tag->tag, head->tag) < 0) {
        tag->next = head;
        head = tag;
    } else {
        p_old = head;
        for (p = head->next; p != NULL &&
        strcmp(tag->tag, p->tag) > 0; p = p->next) {
            p_old = p;
        }
        tag->next = p;
        p_old->next = tag;
    }
    return (head);
}
