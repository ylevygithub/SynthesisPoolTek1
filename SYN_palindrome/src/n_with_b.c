/*
** EPITECH PROJECT, 2019
** palindrome
** File description:
** flag n with -b args
*/

#include "../include/my.h"

void one_iteration(t_calcul calcul, int base)
{
    if (palindrome(calcul.sum_str) == 1) {
        calcul.iter++;
        printf("%s leads to %d in %d iteration(s) in base %d\n",
        calcul.str_begin, calcul.sum, calcul.iter, base);
        exit(0);
    }
}

void no_solution(t_calcul calcul)
{
    if (palindrome(calcul.sum_str) == 0 && calcul.iter > 100) {
        printf("no solution\n");
        exit(0);
    }
}

void found_palindrome(t_calcul calcul, int base)
{
    if (palindrome(calcul.sum_str) == 1) {
        printf("%s leads to %d in %d iteration(s) in base %d\n",
        calcul.str_begin, calcul.sum, calcul.iter, base);
        exit(0);
    }
}

void my_loop_for_n_with_b(char *str, int base, t_calcul calcul)
{
    calcul.iter = 0;
    calcul.nb1 = str_to_int(str);
    calcul.nb_str = intbase_to_str(calcul.nb1, base);
    calcul.nb_str_rev = my_revstr(calcul.nb_str);
    calcul.nb2 = convert_base_res_in_initial_base(calcul.nb_str_rev, 5);
    calcul.sum = calcul.nb1 + calcul.nb2;
    calcul.sum_str = intbase_to_str(calcul.sum, base);
    one_iteration(calcul, base);
    for (calcul.iter = 1; palindrome(calcul.sum_str) == 0; calcul.iter++) {
        calcul.nb_str_rev = my_revstr(calcul.sum_str);
        calcul.nb2 = convert_base_res_in_initial_base(calcul.nb_str_rev, 5);
        calcul.sum = calcul.sum + calcul.nb2;
        calcul.sum_str = intbase_to_str(calcul.sum, base);
        no_solution(calcul);
    }
    found_palindrome(calcul, base);
}

void n_with_b(char *str, int base)
{
    char *str1 = intbase_to_str(str_to_int(str), base);
    t_calcul calcul;
    calcul.str_begin = str;

    if (palindrome(str1) == 1)
        printf("%s leads to %s in %d iteration(s) in base %d\n",
        str, str, 0, base);
    else
        my_loop_for_n_with_b(calcul.str_begin, base, calcul);
}
