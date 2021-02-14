##
## Makefile for Makefile in /home/lblanchard/WireFrame
##
## Made by Leandre Blanchard
## Login   <lblanchard@epitech.net>
##
## Started on  Mon Nov 21 12:31:51 2016 Leandre Blanchard
## Last update Tue Dec 20 17:00:34 2016 Léandre Blanchard
##

NAME    = my_sokoban

CC      = gcc

LIB     = -L./lib -lmy -lncurses -lcsfml-audio

SRCS    = main.c \
	  display.c \
	  str_functions.c \
	  xy_fonctions.c \
	  move.c \
	  check.c \
	  menu.c \
	  scores.c \
	  colors.c \
	  help.c

OBJ     = $(SRCS:.c=.o)

RM      = rm -f

CFLAGS   += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@	tput setaf 2; cat include/signature; tput sgr0
	@	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIB)

clean:
	@	$(RM) $(OBJ)

fclean: clean
	@	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
