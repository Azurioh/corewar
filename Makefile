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

TEST_FLAGS	=	tests/corewar_tests.c	\
				tests/redirect_all_std.c	\
				--coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C lib/my
	gcc -o $(NAME) $(OBJS) -L lib -l my

valgrind:	re
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

clean:
	make clean -C lib/my
	make clean -C bonus
	rm -f $(OBJS)
	rm -f *.vgcore
	rm -f *.gcno *.gcda

fclean:	clean
	make fclean -C lib/my
	make fclean -C bonus
	rm -f $(NAME)
	rm -f unit_tests
	rm -f corewar_bonus bonus/corewar_bonus

re:	fclean	all

unit_tests:	fclean all
	gcc -o unit_tests $(SRC_NO_MAIN) $(LIB_OBJS) $(TEST_FLAGS)

tests_run:	unit_tests
	./unit_tests --verbose
	gcovr --exclude tests
	gcovr --exclude tests --branches

bonus:	fclean
	make -C bonus
	cp bonus/corewar_bonus .
