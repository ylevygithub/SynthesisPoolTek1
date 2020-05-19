#!/bin/bash
# $() = ``

> Makefile
# on recupere le parametre 1 dans la var config_file
config_file=$1

# on gere project_dir dans la var PROJECT_DIR
PROJECT_DIR=$(cat $config_file | grep PROJECT_DIR | cut -d ";" -f2)
echo -e "PROJECT_DIR\t=\t$PROJECT_DIR\n" >> Makefile

# on gere sources_dir dans la var PROJECT_DIR
SOURCES_DIR=$(cat $config_file | grep SOURCES_DIR | cut -d ";" -f2)
echo -e "SOURCES_DIR\t=\t$SOURCES_DIR\n" >> Makefile

#on gere source_filename
source_filename=$(cat $config_file | grep source_filename | cut -d ";" -f2)
c_files=$source_filename

#nbre de .c  exemples : main.c \ truc.c
nbr_words=$(echo $c_files | wc -w)

filename=$(echo $c_files | cut -d " " -f1)
echo -e "SRC\t\t\t=\t$PROJECT_DIR$SOURCES_DIR$filename \\" >> Makefile
for i in `seq 2 $(($nbr_words-1))`;
do      filename=$(echo $c_files | cut -d " " -f$i)
        echo -e "\t\t\t\t$PROJECT_DIR$SOURCES_DIR$filename \\" >> Makefile
done
filename=$(echo $c_files | cut -d " " -f$nbr_words)
echo -e "\t\t\t\t$PROJECT_DIR$SOURCES_DIR$filename\n" >> Makefile

#OBJ
echo -e "OBJ\t\t\t=\t\$(SRC:.c=.o)\n" >> Makefile


HEADERS_DIR=$(cat $config_file | grep HEADERS_DIR | cut -d ";" -f2)
echo -e "HEADERS_DIR\t=\t$HEADERS_DIR\n" >> Makefile

CC=$(cat $config_file | grep CC | cut -d ";" -f2)
echo -e "CC\t=\t$CC\n" >> Makefile

EXEC=$(cat $config_file | grep EXEC | cut -d ";" -f2)
echo -e "EXEC\t=\t$EXEC\n" >> Makefile

echo -e "all:	\$(EXEC)\n" >> Makefile
echo -e "\$(EXEC):	\$(OBJ)\n	\$(CC) -g \$(OBJ) -o \$(EXEC)\n" >> Makefile
echo -e "clean:\n	rm -f \$(OBJ)\n" >> Makefile
echo -e "fclean:	clean\n	rm -f \$(EXEC)\n" >> Makefile
echo -e "re:	fclean all" >> Makefile
