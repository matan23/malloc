OS 		:= $(shell uname)
CC 		= gcc
NAME		= libmy_malloc_$(OS).so
SRC		= malloc.c
OBJ		= $(SRC:%.c=%.o)
RM		= rm -rf
CFLAGS 		= -ansi -pedantic -W -Wall -L. -I.

$(NAME):	$(OBJ)
	$(CC) -shared $(SRC) -o $(NAME) $(CFLAGS)

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
