##
## EPITECH PROJECT, 2024
## corewar
## File description:
## Makefile
##

.PHONY	=	all $(NAME) valgrind clean fclean re unit_tests tests_run

NAME	=	corewar

SRC	=	$(shell find src -name '*.c')

SRC_NO_MAIN	=	$(shell find src -name '*.c' ! -name 'main.c')

OBJS	=	$(SRC:.c=.o)

LIB_OBJS	=	$(shell find lib/my -name '*.o')

CFLAGS	+= -Werror -Wall -Wextra -g

TEST_FLAGS	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C lib/my
	gcc -o $(NAME) $(OBJS) -L lib -l my

valgrind:	re
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

clean:
	make clean -C lib/my
	rm -f $(OBJS)
	rm -f *.vgcore
	rm -f *.gcno *.gcna

fclean:	clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean	all

unit_tests:	fclean
	gcc -o unit_tests $(SRC_NO_MAIN) $(LIB_OBJS) $(TEST_FLAGS)

tests_run:	unit_tests
	./unit_tests --verbose
	gcovr --exclude tests
	gcovr --exclude tests --branches
