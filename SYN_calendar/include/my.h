/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct employee
{
    int id;
    char *last_name;
    char *first_name;
    char *position;
    char *zipcode;
    struct employee *next;
} employee_t;

typedef struct meeting
{
    int id;
    char *date;
    char *zipcode;
    struct meeting *next;
} meeting_t;


int map_len(char **map);
char *my_realloc(char *first, char *second);
char *get_map(size_t len);
char *my_strcpy(char *str);
void putmap(char **map);

int char_verif(char c);
int my_count(char *str);
int my_wordlen(char *str, int i);
char **my_str_to_word_tab(char *str);

int end_verif(char **map);
int wordlen(char *str);
int str_to_int(char *str);
void swap(int *a, int*b) ;

char *recup_data(char *str, int begin);
int *recup_id_for_info_employee(int begin, char *str);
int *recup_id_all_employees(void);


int open_read(char **av);
