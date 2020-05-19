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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct s_generate
{
    char *total;
    int imap;
    int itmp;
};
typedef struct s_generate t_generate;

struct s_setmap
{
    char *buff;
    int size;
    int fd;
    const char *pathname;
    char **map;
};
typedef struct s_setmap t_setmap;

/*requirement.c*/
char *my_strlowcase(char *str);
char *my_strcapitalize_synthesis(char *str);
char first_letter_capital(char *str, int *pti);

/*str_to_word_tab.c*/
int char_verif(char c);
int my_count(char *str);
int my_wordlen(char *str, int i);
char **my_str_to_word_tab(char *str);

/*main.c*/

/*lib.c*/
void my_putchar(char c);
void my_putstr(char *str);
int is_it_number(char *str);
void my_putmap(char **map);
char **newline(char **map, int *pti);

/*lib2.c*/
char *my_realloc(char *last, char *end);
int map_len(char **map);
char *get_map(size_t len);
char *my_strcpy(char *str);
void putmap(char **map);

/*lib3.c*/
int str_to_int(char *str);

/*parsing.c*/
char *parsing_dna(char *str , char *tmp);
char *parsing_identifier(char *str, char *tmp);
void parsing(char **map);
int verif_fasta(char *str);
int big_len(char *str);

/*open_read.c*/
int read_and_parse_one(char **av);
int open_read(char **av);
int read_and_parse_two(char **av);
int read_and_parse_three(char **av);
int read_and_parse_four(char **av, int kmers);

/*argument.c*/
void argument_nbr(char **av);
void arguments(int ac, char **av);

/*parsing_two*/
void parsing2(char **map);
char *parsing2_dna(char *str , char *tmp);

/*parsing_three.c*/
int count_nbr_greater(char **map);
char *finalize(char *str);
char **generate_tmp(char **map);
void parsing3(char **map);
int count_nbr_caratct(char *str);
char *finalize(char *str);

/*count.c*/
int count_nbr_greater(char **map);
int count_nbr_caract(char *str);

/*reverse.c*/
char *my_revstr(char *str);
char **reverse_map(char **map);
char *reverse_complement(char *str);

/*generate.c*/
char *fill_dna(t_generate gen, char **map, char **tmp);
char **generate_tmp(char **map);
char *generate_lines_from_second(t_generate gen, char **map);
char *fill_dna(t_generate gen, char **map, char **tmp);
char **generate_lastline(t_generate gen, char **map, char **tmp);
