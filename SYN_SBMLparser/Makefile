##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=	./src/lib.c \
			./src/parser.c \
			./src/str_to_word_tab.c \
			./src/insert.c \
			./src/tag_exist.c \
			./src/add_attribute.c \
			./src/display.c \
			./src/recup.c \
			./src/ID_option.c \
			./src/ID_option2.c \
			./src/reaction.c \
			requirement.c

OBJ		=	$(SRC:.c=.o)

NAME	=	SBMLparser

CFLAGS = -Wall -Wextra -Werror

all :	$(NAME)

$(NAME) :	$(OBJ)
			@gcc -o $(NAME) $(OBJ) -g $(CFLAGS)
			@echo "###COMPILATION DONE###"
clean	:
		@rm -f $(NAME)
fclean	:	clean
		@rm -f $(OBJ)
		@echo "###ALL CLEAN###"
re	:	fclean all
