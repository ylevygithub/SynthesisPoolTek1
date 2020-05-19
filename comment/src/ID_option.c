/*
** EPITECH PROJECT, 2019
** SBML project
** File description:
** ID option
*/

#include "../include/my.h"

/*The stoichoimetry tag gives the quantity of consumed chemical products

. If ID is the id of a <compartment> tag, the program must print an alphabetical list of id-associated
chemical products on the standard output.
2. If ID is the id of a <species> tag, the program must print a quantified and alphabetical list of the chemical
reactions that consume
a chemical product on the standard output.
3. If ID is the id of a <reaction> tag, the program must print an alphabetical list of the reactants, and
products of the reaction, on the
standard output.
4. Otherwise, the program must print the list of all chemical products.*/

int check_same_value(t_attribute *p, char *value_id)
{
    if (strcmp(p->value, value_id) == 0) {
        return (1);
    }
    return (0);
}

int verifying_if_keyword_isfound(char *value_id, char *attribute_name, t_tag *tag)
{
    int verif;
	t_attribute *p;
	// On parcourt la liste chaînée des attributs
	for (p = tag->head; p != NULL ; p = p->next) {
		// Si on trouve un nom d'attribut qui correspond au paramètre "attribute_name"
		if (strcmp(p->attribute, attribute_name) == 0) {
			// Si la valeur de cet attribut correspond au "value_id" reçu en paramètre
            verif = check_same_value(p, value_id);
		}
	}
    if (verif == 1 && attribute_name == "compartment")
        return (1);
    else if (verif == 1 && attribute_name != "compartment") {
        printf("List of species in compartment %s\n", value_id);
        return (1);
    }
	return (0);
}

char *recup_value(t_tag *tag, char *attribute_name)
{
	t_attribute *p;
	// On parcourt la liste chaînée
	for (p = tag->head; p != NULL ; p = p->next) {
		// Si on rencontre un attribut qui correspond au nom d'attribut "attribute_name"
		if (strcmp(p->attribute, attribute_name) == 0) {
			// On retourne la valeur de l'attribut recherché
			return (p->value);
		}
	}
	return (NULL); 	// Normalement, on ne doit jamais arriver là car le fichier XML était censé
					// être bien formé
}

t_attribute *insert_value(t_attribute *head, char *value)
{
    t_attribute *p;
    t_attribute *p_old;
    t_attribute *attribute = malloc(sizeof(t_attribute));
    attribute->value = value;
    if (head == NULL || strcmp(attribute->value, head->value) < 0) {
        attribute->next = head;
        head = attribute;
    } else {
        p_old = head;
        for (p = head->next; p != NULL &&
        strcmp(attribute->value, p->value) > 0; p = p->next) {
            p_old = p;
        }
        attribute->next = p;
        p_old->next = attribute;
    }
    return (head);
}

void display_value(t_attribute *head)
{
	t_attribute *p;

	for (p = head; p != NULL ; p = p->next) {
		printf("--->%s\n", p->value);
	}
}

t_attribute *id_compartment_chemicalProducts2(t_tag *tag, char *value,
t_attribute *head, char *value_id)
{
    if (verifying_if_keyword_isfound(value_id, "compartment", tag) == 1) {
        value = recup_value(tag, "name");
        head = insert_value(head, value);
    }
    return (head);
}

void id_compartment_chemicalProducts(char **map, int begin, char *value_id)
{
	int i;
	t_tag *tag;
	char *value;
	t_attribute *head = NULL;
    int verif;

	// On parcourt le tableau "map" jusqu'à la fin (on aurait pu optimiser en arrêtant la boucle
	// dès qu'on rencontre "/listOfSpecies")
	for (i = begin; map[i] != 0; i++) {
		// On "splitte" une ligne de "map" dans la variable "tag"
        tag = parsing_line(map[i]);
        // On vérifie si le nom de l'élément est "species"
        if (strcmp(tag->tag, "species") == 0) {
        	// On vérifie si il y a un attribut "compartment" qui correspond au "value_id"
        	if (verifying_if_keyword_isfound(value_id, "compartment", tag) == 1) {
        		// Si c'est le cas, on stocke la valeur de l'attribut "name" 
        		// dans une liste chaînée
                head = id_compartment_chemicalProducts2(tag, value, head, value_id);
        	}
        }
	}
	// On affiche la liste chaînée des valeurs
	display_value(head);
}

void ID_option(char **map, char *value_id)
{
    int i;
    int found = 0;
    t_tag *tag;

    // On parcourt "map" ligne par ligne
    for (i = 0; map[i] != 0 && found == 0; i++) {
    	// On "splitte" une ligne de "map" dans la variable "tag"
        tag = parsing_line(map[i]);					
        											
        // On vérifie si on trouve la valeur d'attribut "value_id" 
        // dans l'attribut "id" de la variable "tag" qu'on vient de créer
        found = verifying_if_keyword_isfound(value_id, "id", tag);
    }
    // Si on a quitté la boucle car on a trouvé	le keyword_id
	if (found == 1) {
        // ID is the id of a <compartment> tag
        if (strcmp(tag->tag, "compartment") == 0) {
        	// On va chercher les éléments "species" dans la map. Chaque fois qu'on en trouve un, 
        	// on vérifiera si la valeur de l'attribut "compartment" vaut bien le "value_id". 
        	// Si oui, on affiche la valeur du "name"
        	// Remarque : je transmets "i" pour "optimiser" la fonction. Il est inutile de 
        	// parcourir à nouveau toutes les lignes de "map". On peut directement parcourir map
        	// à partir de l'élément qui suit "compartement" (on peut même facilement sauter
        	// 2 lignes de plus)
            id_compartment_chemicalProducts(map, i, value_id);
        }
        // Si on a quitté la boucle et qu'on N'a PAS trouvé le value_id 
    }
    else {
        print_list();
    }
}
