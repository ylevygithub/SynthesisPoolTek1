/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** my.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

struct s_setmap
{
    char *buff;
    int size;
    int fd;
    const char *pathname;
    char **map;
};
typedef struct s_setmap t_setmap;

struct s_attribute
{
    char *attribute;
    char *value;
    struct s_attribute *next;
};
typedef struct s_attribute t_attribute;

struct s_tag
{
    char *tag;
    t_attribute *head;
    struct s_tag *next;
};
typedef struct s_tag t_tag;

/*lib.c*/
void  my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
void my_putmap(char **map);
int my_char_isalphamin(char c);

/*requirement.c*/
int char_verification(char c);
int counter(char const *str);
int wordlen(char const *str, int i);
char **my_str_to_word_array_synthesis(char const *str);

/*str_to_word_tab.c*/
int char_verif(char c);
int my_count(char *str);
int my_wordlen(char *str, int i);
char **my_str_to_word_tab(char *str);

/*parser.c*/
t_tag *parsing_line(char *line);
int parsing(char **map);
int open_read_and_parse(char **av);
int open_read_and_parse_option(char **av);

/*insert.c*/
t_tag *insert(t_tag *tag, t_tag *head);

/*tag_exist.c*/
int tag_exist(t_tag *tag, t_tag *head);

/*add_attribute.c*/
t_attribute *insert_attribute(t_attribute *head, char *name, char *value);

/*display.c*/
void display_tag(t_tag *tag);
void display_all(t_tag *head);
void display_value(t_attribute *head);
void display_all_value(t_attribute *head);

/*recup.c*/
char *recup(int begin, int end, char *line);
char *recup_tag(char *line, int *pti);
char *recup_name_attribute(int *pti, char *line);
char *recup_value_attribute(int *pti, char *line);

/*ID_option.c*/
int check_same_value(t_attribute *p, char *value_id);
int verifying_if_keyword_isfound(char *value_id,
    char *attribute_name, t_tag *tag);
t_attribute *id_compartment_chemicalProducts2(t_tag *tag,
    t_attribute *head, char *value_id);
void id_compartment_chemicalProducts(char **map, int begin, char *value_id);
void ID_option(char **map, char *value_id);

/*ID_option2.c*/
char *recup_value(t_tag *tag, char *attribute_name);
t_attribute *insert_value(t_attribute *head, char *value);
t_attribute *all_chemicalProducts(t_tag *tag,
t_attribute *head, char *value_id);
void id_not_found(char **map, int begin, char *value_id);

/*reaction.c*/
char *get_value_by_name(t_tag *tag, char *attribute_name);
t_attribute *recup_reactants(char **map, int *begin);
void id_reaction_reactantsAndProducts(char **map, int begin, char *value_id);
