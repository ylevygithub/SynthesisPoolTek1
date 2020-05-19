void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
}
void show_list(list_t *list)
{
    list_t *temp = list;

    while (temp) {
        my_putstr(temp->data);
        my_putchar('\n');
        temp = temp->next;
    }
}

list_t *init_list(void)
{
    list_t *list;
    if ((list = malloc(sizeof(list_t))) == NULL)
        return (NULL);
    list->next = NULL;
    list->data = NULL;
    return (list);
}
char *my_strcpy(char *str)
{
    int it = 0;
    char *temp;

    while (str[it])
        it++;
    if ((temp = malloc(sizeof(char) * it + 1)) == NULL)
        exit(84);
    it = 0;
    while (str[it]) {
        temp[it] = str[it];
        it++;
    }
    temp[it] = '\0';
    return (temp);
}
list_t *add_list(list_t *list, char *str)
{
    list_t *temp;
    list_t *news;

    temp = list;
    if (temp->data == NULL){
        temp->data = str;
        return (list);
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        news = init_list();
        news->data = my_strcpy(str);
        temp->next = news;
        return (list);
    }
}
int my_revlist_synthesis(list_t **begin)
{
    list_t *tmp = *begin;
    list_t *head_tmp = NULL;
    list_t *head_tmp1 = NULL;

    for (list_t *head_tmp1 = NULL; tmp != NULL; tmp = head_tmp1) {
        head_tmp1 = tmp->next;
        tmp->next = head_tmp;
        head_tmp = tmp;
        tmp = head_tmp1;
    }
    *begin = head_tmp;
    return 0;
}

list_t *my_findnodeeqinlist_synthesis(list_t *begin, void *data_ref,
int (*cmp)(void *, void *))
{
    list_t *tmp = begin;

    for (;tmp != NULL && cmp(data_ref, tmp->data) != 0; tmp = tmp->next);
    if (cmp(data_ref, tmp->data) != 0)
        return (NULL);
    return (tmp);
}

int main(int ac, char **av)
{
    list_t **list = malloc(sizeof(list_t *));
    list_t *test;
    int it = 0;

    list[0] = init_list();
    while (it < ac) {
       add_list(list[0], av[it]);
       it++;
    }
    printf("LISTE NORMAL :\n\n");
    show_list(list[0]);
    my_revlist_synthesis(list);
    printf("LISTE REV :\n\n");
    show_list(list[0]);
    printf("\nSECOND PART :\n\n");
    test = my_findnodeeqinlist_synthesis(list[0], "moi", );
    if (test != NULL) {
        my_putstr(test->data);
        my_putchar('\n');
    }
    return (0);
}

