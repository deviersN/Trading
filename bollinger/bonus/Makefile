##
## EPITECH PROJECT, 2018
## Bollinger
## File description:
## trade
##

CC	= gcc

RM	= rm -rf

NAME	= bollinger

SRC	= src/bollinger.c	\
	  src/usage.c		\
	  src/error.c		\
	  src/errormessage.c	\
	  src/getvalues.c	\
	  src/algorithm.c	\
	  src/curses.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wall -Wextra -Iinclude -lm -lncurses -g3 -ggdb

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

a:	all clean

.PHONY: all clean fclean re a