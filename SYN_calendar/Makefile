##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		src/main.c

OBJ		=		$(SRC:.c=.o)

NAME =	calendar

all:	$(NAME)

$(NAME):	 $(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f devnull

fclean: clean
	rm -f $(NAME)

re: fclean all
