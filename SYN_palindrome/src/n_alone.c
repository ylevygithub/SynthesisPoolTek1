/*
** EPITECH PROJECT, 2019
** palindrome
** File description:
** flag n without args
*/

#include "../include/my.h"


t_calcul my_loop_for_n_alone(char *str, int base, t_calcul calcul)
{
    for (int iterations = 0; palindrome(str) == 0; iterations++) {
        calcul.nb_str = intbase_to_str(str_to_int(str), base);
        calcul.nb_str_rev = my_revstr(calcul.nb_str);
        calcul.nb1 = str_to_int(calcul.nb_str);
        calcul.nb2 = str_to_int(calcul.nb_str_rev);
        calcul.sum = calcul.nb1 + calcul.nb2;
        calcul.sum_str = int_to_str(calcul.sum);
        str = calcul.sum_str;
        if (palindrome(str) == 1) {
            iterations++;
            printf("%s leads to %s in %d iteration(s) in base %d\n",
            calcul.str_begin, str, iterations, base);
        }
    }
    if (palindrome(str) == 0)
        printf("no solution\n");
    return (calcul);
}

void n_alone(char *str)
{
    t_calcul calcul;
    calcul.str_begin = str;
    str = intbase_to_str(str_to_int(str), 10);

    if (palindrome(calcul.str_begin) == 1)
        printf("%s leads to %s in %d iteration(s) in base %d\n",
        calcul.str_begin, calcul.str_begin, 0, 10);
    calcul = my_loop_for_n_alone(str, 10, calcul);
}
