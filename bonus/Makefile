##
## EPITECH PROJECT, 2024
## corewar
## File description:
## Makefile
##

.PHONY	=	all $(NAME) valgrind clean fclean re unit_tests tests_run

NAME	=	corewar_bonus

SRC	=	$(shell find src -name '*.c')

SRC_NO_MAIN	=	$(shell find src -name '*.c' ! -name 'main.c')

OBJS	=	$(SRC:.c=.o)

LIB_OBJS	=	$(shell find ../lib/my -name '*.o')

CFLAGS	+= -Werror -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJS) -L ../lib -l my -lncurses

valgrind:	re
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

clean:
	make clean -C ../lib/my
	rm -f $(OBJS)
	rm -f *.vgcore
	rm -f *.gcno *.gcda

fclean:	clean
	make fclean -C ../lib/my
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean	all
