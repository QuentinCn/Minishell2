##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root minishell2
##

SRC		=	src/interpreter.c	\
			src/path.c		\
			src/input.c		\
			src/command.c		\
			src/command_format.c	\
			src/do_exit.c		\
			src/do_cd.c		\
			src/env.c		\
			src/execve.c		\
			src/without_execve.c

SRC_MAIN	=	src/main.c

SRC_TESTS	=	tests/tests_minishell2.c\
			tests/tests_env.c	\
			tests/tests_cd.c

OBJ		= 	${SRC:.c=.o}

OBJ_MAIN	= 	${SRC_MAIN:.c=.o}

OBJ_TESTS	= 	${SRC_TESTS:.c=.o}

NAME		= 	mysh

TESTS_NAME	=	unit_tests

CFLAGS		= 	-W -Wall -Wextra

CPPFLAGS	= 	-I./include

LDFLAGS		= 	-L./lib -lmy

all:	binairy

libmy:
	make -C lib/

my_printf:
	make -C my_printf/

binairy: my_printf libmy $(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(SRC) $(SRC_MAIN) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS)

tests_run: LDFLAGS += -lcriterion --coverage
tests_run: fclean my_printf libmy $(OBJ_TESTS) $(OBJ)
	gcc -o $(TESTS_NAME) $(SRC) $(SRC_TESTS) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS)
	./$(TESTS_NAME) && gcovr . --html-details --html -o covr.html --exclude tests/

clean:
	make -C my_printf/ clean
	make -C lib/ clean
	rm -f *.gc*
	rm -f *.html
	rm -f $(OBJ)
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ_TESTS)

fclean: clean
	make -C my_printf/ fclean
	make -C lib/ fclean
	rm -f $(NAME)
	rm -f $(TESTS_NAME)

re: fclean all

.PHONY: clean fclean re all libmy binairy my_printf
