/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** check if tag exist or not to not display it more than one time
*/

#include "../include/my.h"

int tag_exist(t_tag *tag, t_tag *head)
{
    t_tag *p;

    for (p = head; p != NULL; p = p->next) {
        if (strcmp(tag->tag, p->tag) == 0)
            return (1);
    }
    return (0);
}
