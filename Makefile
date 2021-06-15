##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## generic Makefile
##

SRC	=	main.cpp	\

CC	=	g++

NAME	=	cipher

OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-Wall -Wextra -g3

all:	core

core:
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
