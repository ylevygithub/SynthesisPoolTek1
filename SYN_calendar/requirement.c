/*
** EPITECH PROJECT, 2019
** calendar
** File description:
** requirement.c
*/

#include "requirement.h"
#include <stdio.h>

int my_revlist_synthesis(list_t **begin)
{
    list_t *tmp = *begin;
    list_t *head_tmp = NULL;
    list_t *head_tmp1 = NULL;

    for (list_t *head_tmp1 = NULL; tmp != NULL; tmp = head_tmp1) {
        head_tmp1 = tmp->next;
        tmp->next = head_tmp;
        head_tmp = tmp;
        tmp = head_tmp1;
    }
    *begin = head_tmp;
    return 0;
}

list_t *my_findnodeeqinlist_synthesis(list_t *begin, void *data_ref,
int (*cmp)(void *, void *))
{
    list_t *tmp = begin;

    for (;tmp != NULL && cmp(data_ref, tmp->data) != 0; tmp = tmp->next);
    return (tmp);
}
