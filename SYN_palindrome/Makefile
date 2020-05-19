##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC		=		./src/main.c \
				./src/lib.c \
				./src/n_alone.c \
				./src/n_with_b.c \
				./src/arguments.c \
				./src/palindrome_check.c \
				./src/lib2.c \
				./src/n_with_max.c \
				./src/n_with_min.c \
				./src/n_with_maxmin.c \
				requirement.c

OBJ		=		$(SRC:.c=.o)

NAME	=		palindrome

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc -g $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
