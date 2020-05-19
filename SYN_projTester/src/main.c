/*
** EPITECH PROJECT, 2019
** projtester
** File description:
** main
*/

#include "../include/my.h"

void my_output(char *TRD, char *outputfile)
{
    int fd = open(outputfile, O_RDONLY);

    if (fd == -1)
        open(outputfile, O_RDONLY | O_CREAT);
    else
        exit(84);
}

void arguments(int ac, char **av, int cat, int echo)
{
    switch (ac) {
        case 1: exit(84); break;
        case 2: my_tree(av[1]); break;
        case 3:
            if (strcmp(av[2], "cat") == 0)
                my_cat(av[1]);
            else if (strcmp(av[2], "echo") == 0)
                my_echo(av[1]);
            else
                my_output(av[1], av[2]);
        default:
            exit(84);
            break;
    }
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    int cat;
    int echo;

    if (fd == -1)
        exit(84);
    arguments(ac, av, cat, echo);
    return (0);
}
