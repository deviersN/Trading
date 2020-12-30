##
## EPITECH PROJECT, 2018
## Trade
## File description:
## Makefile
##

CXX	= g++

RM	= rm -rf

SRC	= src/Trade.cpp		\
	  src/MarketPlace.cpp	\
	  src/Mobil.cpp

OBJ	= $(SRC:.cpp=.o)

NAME	= trade

CXXFLAGS= -W -Wall -Wextra -Iinclude -g3 -ggdb

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(SRC) $(CXXFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

a: all clean

.PHONY: all clean fclean re a
