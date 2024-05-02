##
## EPITECH PROJECT, 2024
## my_lib_c
## File description:
## Makefile
##

NAME	=	libmy.a

SRC	=	$(shell find . -name '*.c')

OBJS	=	$(SRC:.c=.o)

CFLAGS	+= -Werror -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	cp -r lib_includes my.h ../../include
	cp $(NAME) ../

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) ../$(NAME)

re: fclean all
