##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC		=		./src/main.c \
				./src/print_inside_directory.c \
				./src/lib.c \
				./src/my_pid.c \
				./src/number_of_files.c \
				./src/move_tab.c \
				./src/add_file.c \
				./src/recup_name.c \
				./src/print_tab.c \
				./src/parsing_av.c \
				./src/print_inside_dir_for_cat.c \
				./src/print_inside_dir_for_echo.c \
				./src/remove_tdf.c \
				./src/my_cat.c \
				./src/my_echo.c \
				./src/print_tab_for_cat.c \
				./src/print_tab_for_echo.c \
				./src/brackets.c \
				./src/recup_for_cat.c \
				./src/recup_for_echo.c \
				./src/my_str_to_word_tab.c \
				./src/tree.c

OBJ		=		$(SRC:.c=.o)

NAME	=		projTester

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc -g $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
