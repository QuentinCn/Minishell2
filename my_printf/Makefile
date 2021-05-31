##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## lib my_sokoban
##

SRC	=	$(shell find -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	../lib/libmy.a

CPPFLAGS= 	-I./../include

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all $(NAME) clean fclean re
