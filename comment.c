

int number_files(char *dir_name)
{
    struct dirent *dirent;
    DIR *dir;
    int counter = 0;

    dir = opendir(dir_name);
    while ((dirent = readdir(dir)) != 0) {
        if ((dirent->d_name[0] != '.')) {
            counter++;
        }
    }
    closedir(dir);
    return (counter);
}

void move_tab(char **tab_files, int begin)
{
    int i = begin;

    while (tab_files[i] != NULL) {
        i++;
    }
    tab_files[i+1] = NULL;
    while(i > begin) {
        tab_files[i] = my_strcpy(tab_files[i-1]);
        i--;
    }
}

void add_file(char **tab_files, char *file_name)
{
    int i = 0;

    // 1. Repérer où insérer
    while (tab_files[i] != NULL && strcmp(file_name, tab_files[i]) > 0) {
        i++;
    }
    // 2. Insérer et faire le décalage
    if (tab_files[i] == NULL) {
        tab_files[i] = malloc(sizeof(char) * (strlen(file_name) + 1));
        strcpy(tab_files[i], file_name);
        tab_files[i+1] = NULL;
    } else {
        // 2.1. Décalage
        move_tab(tab_files, i);

        // 2.2. Insersion
        tab_files[i] = malloc(sizeof(char) * (strlen(file_name) + 1));
        strcpy(tab_files[i], file_name);
    }
}

char **recup_name(char **tab_files)
{
    struct dirent *dirent;
    DIR *dir;

    dir = opendir(".");
    while ((dirent = readdir(dir)) != 0) {
        if ((dirent->d_name[0] != '.')) {
            // On stocke le nom du fichier ou du répertoire dans un tableau
            add_file(tab_files, dirent->d_name);
        }
    }
    closedir(dir);
    return tab_files;
}
void print_inside_directory(char* dir_name, int level)
{
    char **tab_files;
    int nbr;

    // 1. On teste si c'est un répertoire
    if (chdir(dir_name) == -1)
        return;

    // 2. Connaître le nombre de fichiers/rep du dossier pour allouer l'espace nécessaire pour le tableau
    nbr = number_files(".");
    tab_files = malloc( sizeof(char*) * (nbr+1));
    tab_files[0] = NULL;

    // 3. On repère les noms de fichiers et de répertoire
    tab_files = recup_name(tab_files);

    // 4. On parcourt le tableau
    print_tab(tab_files, level);

    // 5. On remonte d'un répertoire
    chdir("..");
}

void print_tab(char **tab_files, int level)
{
    int i = 0;
    int j;

    while (tab_files[i]) {
        for (j = 1;j <= level; j++){
            printf("-----");
        }
        printf("%s\n", tab_files[i]);
        print_inside_directory(tab_files[i], level+1);
        i++;
    }
}

void my_tree(char *chemin)
{
    DIR *dir;

    if (chemin == NULL)
        exit(0);

    dir = opendir(chemin);
    if(dir == NULL) {   // Ce n'est pas un dossier
        exit(84);
    }
    closedir(dir);

    printf("%s\n", chemin);
    print_inside_directory(chemin, 1);
}

int main(int ac, char **av)
{
    my_tree(av[1]);
    return (0);
}
