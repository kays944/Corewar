##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

TESTS 			=

SRC_MAIN 		= 	src/main.c

SRC				=	src/main.c						\
					src/corewar.c 					\
					src/helper.c 					\
					src/op.c 						\
					src/parsing.c 					\
					src/read_champions.c 			\
					src/get_pos.c 					\
					src/init_proc.c 				\
					src/main_loop.c 				\
					src/dump.c 						\
					src/execution.c 				\
					src/utils/array_count.c 		\
					src/utils/free_array.c 			\
					src/utils/my_itoa.c 			\
					src/utils/my_putstr.c 			\
					src/utils/my_strcat.c 			\
					src/utils/my_strcmp.c 			\
					src/utils/my_strcpy.c 			\
					src/utils/my_strdup.c 			\
					src/utils/my_strlen.c			\
					src/utils/my_strncmp.c 			\
					src/utils/my_strndup.c			\
					src/utils/str_split.c			\
					src/utils/read_file.c			\
					src/utils/my_getnbr.c			\
					src/utils/my_strncpy.c			\

SRC_TESTS 		= 	$(filter-out $(SRC_MAIN), $(SRC))

OBJ_DIR			=	obj

OBJ				=	$(SRC:src/%.c=$(OBJ_DIR)/%.o)

CC 				:= 	epiclang

NAME			= 	corewar

CFLAGS			=

CPPFLAGS 		=	-I./include

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/utils

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) *.gc*

fclean:		clean
	$(RM) $(NAME)
	$(RM) ./unit_tests

re:	fclean all

tests_run: CPPFLAGS += --coverage -lcriterion
tests_run: 	clean
	$(CC) -o unit_tests $(TESTS) $(SRC_TESTS) $(CFLAGS) $(CPPFLAGS)
	-./unit_tests

debug: CFLAGS += -g3
debug:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re tests_run debug
