##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC		=		./src/main.c \
				./src/lib.c \
				./src/lib2.c \
				./src/str_to_word_tab.c \
				./src/argument.c \
				./src/parsing.c \
				./src/open_read.c \
				./src/parsing_two.c \
				./src/parsing_three.c \
				./src/generate.c \
				./src/reverse.c \
				./src/count.c \
				requirement.c

OBJ		=		$(SRC:.c=.o)

NAME	=		FASTAtools

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc -g $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
