##
## EPITECH PROJECT, 2019
## automakefile
## File description:
## automakefile
##

SRC		=		main.c

OBJ		=		$(SRC:.c=.o)

PROJECT_DIR	=		automakefile

all:	$(PROJECT_DIR)

$(PROJECT_DIR):		$(OBJ)
	gcc -g $(OBJ) -o $(PROJECT_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(PROJECT_DIR)

re: fclean all
