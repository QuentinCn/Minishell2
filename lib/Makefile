##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root minishell2
##

SRC		=	my_str_to_word_array.c	\
			concat_str.c		\
			my_strdup.c		\
			free.c			\
			my_strcmp.c		\
			array_len.c		\
			cut_env_line.c		\
			concat_array.c		\
			delete_line_in_array.c	\
			chained_list.c

OBJ		= 	${SRC:.c=.o}

NAME		= 	libmy.a

TESTS_NAME	=	unit_tests

CFLAGS		= 	-W -Wall -Wextra

CPPFLAGS	= 	-I./../include

all:	binairy

binairy: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all binairy
