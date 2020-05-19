PROJECT_DIR	=	fakeProj1

SRC	=	./$(wildcard *.c)

CFLAGS	=	-ftest-coverage -O2

OBJ			=	$(SRC:.c=.o)

HEADERS_DIR	=	include

CC	=	gcc

EXEC	=	fakeProj

all:	$(EXEC)

$(EXEC):	$(OBJ)
	$(CC) -o $(EXEC) $(SRC) $(CFLAGS)

archive:
	tar -cvvf test.tar ../fakeProj1
	mv test.tar backup

	@echo -e "test.tar file generated."

delete:
	rm -f ./backup/test.tar

revert:
	tar -xvf backup/test.tar

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *~
	rm -f backup/test.tar

fclean:	clean
	rm -f $(EXEC)

re:	fclean all
