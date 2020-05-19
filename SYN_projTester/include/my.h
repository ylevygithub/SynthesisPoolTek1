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
#include <sys/wait.h>
#include <dirent.h>

void print_tab(char **tab_files, int level);
char *my_strcpy(char *str);
int number_files(char *dir_name);
void move_tab(char **tab_files, int begin);
void add_file(char **tab_files, char *file_name);
char **recup_name(char **tab_files);
void print_inside_directory(char* dir_name, int level);
void my_tree(char *);
void print_tab(char **tab_files, int level);
int verif_slash(char *str);
char *remove_end_slash(char *str);
char *parsing_av(char *str);
void my_echo(char *chemin);
void my_cat(char *chemin);
void print_inside_directory_for_echo(char *dir_name, char *path);
char *remove_args(char *file_content);
char *recup_args_for_echo(char *file);
char *remove_args_for_cat(char *file_content);
char *recup_input(char *file_content);
char **recup_args_for_cat(char *file);
void print_inside_directory_for_cat(char *dir_name, char *path);
void print_tab_for_echo(char **tab_files, char *path);
char **recup_for_cat2(char **tab, char **cmd);
void print_tab_for_cat(char **tab_files, char *path);
char *brackets(char *path);
char *remove_tdf(char *str);
int verif_dot(char *str);
void my_putchar(char c);
void my_putstr(char *str);
char *my_realloc(char *first, char *second);
char *remove_tdf(char *str);
int my_pid(char *concat_path_cmd, char **cmd, char **my_env);
void arguments(int ac, char **av, int cat, int echo);
void execute_cat(char **cmd);

int char_verif(char c);
int my_count(char *str);
int my_wordlen(char *str, int i);
char **my_str_to_word_tab(char *str);
