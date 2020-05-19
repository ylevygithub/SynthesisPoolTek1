/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct s_calcul
{
    char *str_begin;
    int iter;
    char *nb_str;
    char *nb_str_rev;
    unsigned long nb1;
    unsigned long nb2;
    unsigned long sum;
    unsigned long finalnb;
    char *finalstr;
    char *sum_str;
};
typedef struct s_calcul t_calcul;

struct s_values
{
    int counter;
    char *new_nbstr;
};
typedef struct s_values t_values;

/*requirement.c*/
int my_squareroot_synthesis(int nb);
int my_factrec_synthesis(int nb);

/*lib.c*/
char *my_revstr(char *);
char *intbase_to_str(long long nb, int base);
char *int_to_str(long long nb);
unsigned long str_to_int(char *str);
int is_it_number(char *str);

/*lib2.c*/
int my_compute_power_it(int nb, int p);
unsigned long convert_base_res_in_initial_base(char *str, int base);
int index_pair_is_not_nbr(char **av);

/*n_alone.c*/
t_calcul my_loop_for_n_alone(char *str, int base, t_calcul calcul);
void n_alone(char *str);

/*n_with_b.c*/
void my_loop_for_n_with_b(char *str, int base, t_calcul calcul);
void n_with_b(char *str, int base);
void one_iteration(t_calcul calcul, int base);
void no_solution(t_calcul calcul);
void found_palindrome(t_calcul calcul, int base);

/*arguments.c*/
int three_arguments(char **av);
int five_arguments(char **av);
void seven_arguments(int ac, char **av);
void nine_arguments(int ac, char **av);

/*p_alone.c*/
void p_alone(char *str);

/*palindrome.c*/
int palindrome(char *);

/*main.c*/
void error_management(int ac, char **av);

/*n_with_max.c*/
void no_solution_max(t_calcul calcul, int max);
void my_loop_for_n_with_max(char *str, int base, t_calcul calcul, int max);
void n_with_max(char *str, int base, int max);

/*n_with_min.c*/
void no_solution_min(t_calcul calcul, int min);
void my_loop_for_n_with_min(char *str, int base, t_calcul calcul, int min);
void n_with_min(char *str, int base, int min);

/*n_with_maxmin.c*/
void no_solution_maxmin(t_calcul calcul, int min, int max);
void my_loop_for_n_with_maxmin(char *str, int base, t_calcul calcul,
int min, int max);
void n_with_maxmin(char *str, int base, int min, int max);
