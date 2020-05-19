/*
** EPITECH PROJECT, 2019
** requirement.h
** File description:
** requirement.h
*/

#include <unistd.h>
#include <stdlib.h>

typedef struct list
{
    void *data;
    struct list *next;
} list_t;
