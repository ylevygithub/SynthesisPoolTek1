/*
** EPITECH PROJECT, 2019
** FASTAtools
** File description:
** open read
*/

#include "../include/my.h"

employee_t *employees_head = NULL;
meeting_t *meetings_head = NULL;

char *recup_data(char *str, int begin)
{
    int i = begin;
    int x = 0;
    char *tmp = malloc(sizeof(char) * wordlen(str) + 1);

    while (str[i] != ' ' && str[i] != '\0') {
        tmp[x] = str[i];
        i++;
        x++;
    }
    tmp[x] = '\0';
    return (tmp);
}

int *recup_id_for_info_employee(int begin, char *str)
{
    int i = begin;
    int *nbs = malloc(sizeof(int));
    int size = 0;
    char *number = recup_data(str, i);

    nbs[0] = str_to_int(recup_data(str, i));
    size++;
    i += strlen(number) + 1;
    while (str[i - 1] != '\0') {
        nbs = realloc(nbs, sizeof(int) * (size+1));
        number = recup_data(str, i);
        nbs[size] = str_to_int(number);
        size++;
        i += strlen(number) + 1;
    }
    nbs = realloc(nbs, sizeof(int) * (size+1));
    nbs[size] = -1;
    return (nbs);
}

int *recup_id_all_employees(void)
{
    employee_t *employee = employees_head;
    int *nbs = NULL;
    int count = 0;

    while (employee != NULL) {
        count++;
        employee = employee->next;
    }
    nbs = malloc(sizeof(int) * (count + 1));
    count = 0;
    for (employee=employees_head;employee!=NULL;employee=employee->next) {
        nbs[count] = employee->id;
        count++;
    }
    nbs[count] = -1;
    return (nbs);
}


void display_employee(employee_t *employee)
{
    printf("*****************************\n");
    printf("%s %s\nposition: %s\ncity: %s\n", employee->first_name,
    employee->last_name, employee->position, employee->zipcode);
    // printf("id = %d\n", employee->id);
}

void new_employee(char *str)
{
    int i = 13;
    employee_t *employee = malloc(sizeof(employee_t));

    employee->last_name = recup_data(str, i);
    i += strlen(employee->last_name) + 1;
    employee->first_name = recup_data(str, i);
    i += strlen(employee->first_name) + 1;
    employee->position = recup_data(str, i);
    i += strlen(employee->position) + 1;
    employee->zipcode = recup_data(str, i);
    i += strlen(employee->zipcode) + 1;
    employee->id = str_to_int(recup_data(str, i));
    employee->next = NULL;
//    display_employee(employee);
    employee->next = employees_head;
    employees_head = employee;
}

// Cette fonction recherche et retourne un employé sur son ID
// La liste chaînee est parcourue maillon par maillon. Quand le bon employé est trouvé, il est retourné.
employee_t *search_employee_by_id(int id)
{
    employee_t *employee;

    for (employee=employees_head; employee!=NULL; employee=employee->next) {
        if(employee->id == id) {
            return (employee);
        }
    }
    return NULL;
}

void sort_by_id(int *nbs)
{
    int count = 0;
    int size_total;
    int id_small;

    while (nbs[count] != -1)// A placer dans une fonction
        count++;
    size_total = count;
    count = 1;
    while (count <= size_total - 1) {
        id_small = nbs[count-1];
        for (int i = count; i <= size_total - 1; i++) {
            if (nbs[i] < id_small) {
                id_small = nbs[i];
                swap(&nbs[i], &nbs[count-1]);
            }
        }
        count++;
    }
}

void sort_by_name(int *nbs)
{
    int count = 0;
    int size_total;
    int id_small;
    employee_t *employee_small;
    employee_t *employee_i;

    while (nbs[count] != -1)// A placer dans une fonction
        count++;
    size_total = count;
    count = 1;
    while (count <= size_total - 1) {
        id_small = nbs[count-1];
        employee_small = search_employee_by_id(id_small);   // On récupère les infos complètes de l'employé dont l'id est id_small
        for (int i = count; i <= size_total - 1; i++) {
            employee_i = search_employee_by_id(nbs[i]); // On récupère les infos complètes de l'employé dont l'id est nbs[i]
            if (strcmp(employee_i->last_name, employee_small->last_name) < 0) {
                id_small = nbs[i];
                employee_small = search_employee_by_id(id_small);
                swap(&nbs[i], &nbs[count-1]);
            }
        }
        count++;
    }
}


void display_sort_employees(int *nbs)
{
    employee_t *employee;
    int i;

    for(i = 0; nbs[i] != -1; i++) {
        employee = search_employee_by_id(nbs[i]);
        display_employee(employee);
    }
}

void info_employee(char *str)
{
    int i = 15;
    char *sortByE = recup_data(str, i);
    int *nbs;
    i += strlen(sortByE) + 1;

    // Le but de cette alternative est de créer le tableau nbs (tableau qui contient les ID)
    if (str[i - 1] != '\0') {   // Il y a des ID après la commande
        nbs = recup_id_for_info_employee(i, str);
    }
    else// Il n'y a pas d'ID après la commande
        nbs = recup_id_all_employees();

    if (strcmp(sortByE, "sortById") == 0){
        sort_by_id(nbs);
        display_sort_employees(nbs);
    }
    if (strcmp(sortByE, "sortByName") == 0){
        sort_by_name(nbs);  
        display_sort_employees(nbs);
    }
    if (strcmp(sortByE, "sortByForename") == 0){
        
    }
    if (strcmp(sortByE, "sortByJob") == 0){
        
    }
    if (strcmp(sortByE, "sortByZip") == 0){
        
    }
}

void parsing_all(char **map)
{
    for (int i = 0;strcmp(recup_data(map[i], 0), "END") != 0; i++) {
        if (strcmp(recup_data(map[i], 0), "new_employee") == 0)
            new_employee(map[i]);
        if (strcmp(recup_data(map[i], 0), "info_employees") == 0)
            info_employee(map[i]);
    }
}

int open_read(char **av)
{
    size_t size = 0;
    char *buff = get_map(size);
    char **map = my_str_to_word_tab(buff);
    end_verif(map);
    parsing_all(map);
    free(map);
    exit(0);
}
