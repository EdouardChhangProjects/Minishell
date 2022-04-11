##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC    =	src/minishell/minishell.c 		\
			src/minishell/get_params.c 		\
			src/minishell/is_exec.c			\
			src/minishell/filecat.c			\
			src/minishell/signal.c			\
			src/minishell/builtin.c			\
			src/minishell/str_to_array.c	\
			src/builtins/env_func.c			\
			src/builtins/builtin_cd.c		\
			src/builtins/setenv.c			\
			src/builtins/unsetenv.c

TEST_SRC    =

TEST_OBJ    =   $(TEST_SRC:.c=.o)

MAIN_SRC    =    src/main.c                \

MAIN_OBJ    =    $(MAIN_SRC:.c=.o)        \

OBJ    =    $(SRC:.c=.o)

NAME    =    mysh

LDLIB    =    -lmyll
LIBMY    = 	   lib/libmyll.a

CPPFLAGS    +=    -I./include/ -Wall -Wextra
CFLAGS        +=
LDFLAGS        += -L ./lib

all:	$(NAME)

$(NAME):    $(LIBMY) $(OBJ) $(MAIN_OBJ)
	$(CC) -o $@ $(OBJ) $(MAIN_OBJ) $(LIB) $(LDLIB) $(LDFLAGS) $(CPPFLAGS)

$(LIBMY):
	make -C lib/linked_list/

unit_tests:    fclean
unit_tests:    $(LIBMY)
unit_tests:    CFLAGS    += --coverage
unit_tests:    LDFLAGS    += --coverage -lcriterion
unit_tests:		$(TEST_OBJ) $(OBJ)
	$(CC) -o $@ $(TEST_OBJ) $(OBJ) $(LIB) $(LDFLAGS)
	./$@

debug:	CPPFLAGS += -g
debug:	all
	valgrind ./$(NAME)

gcovr:
	gcovr --exclude tests
	gcovr --exclude tests --branches

clean:
	make clean -C./lib/linked_list/
	rm -f $(OBJ) $(MAIN_OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	make fclean -C ./lib/linked_list/
	rm -f unit_tests
	rm -f $(TEST_OBJ)
	rm -f $(NAME)
	rm -f *.gc*

re:	fclean all

.PHONY:	all clean fclean re gcovr unit_tests
