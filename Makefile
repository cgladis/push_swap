NAME = push_swap
LIBFT_NAME = libft.a
MAIN_NAME = ./src/push_swap.c
CHECKER_FILE = ./src/checker.c
CHECKER_NAME = checker
HFILENAME = ./src/push_swap.h
PYTHON_CHECKER = ./checker_python/checker_push_swap.py
TEST_STACK = 9 1 3 5 0 2
PRINT_CHECK = 0
PRINT_ALL = 0

SRC_NAME = push_swap_instructions.c first_check.c\
push_swap_utils0.c push_swap_utils1.c run_commands.c print_functions.c\
bubble_sort.c insertion_sort0.c insertion_sort1.c \
insertion_sort_extended0.c insertion_sort_extended1.c error_manegment.c \
push_swap_utils2.c insertion_sort_extended2.c

CC = gcc

LIB_PATH = ./libft/
SRC_PATH = ./src/
OBJ_PATH = ./obj/

FLAGS = -Wall -Wextra -Werror -D PRINT_CHECK=$(PRINT_CHECK) \
-D PRINT_ALL=$(PRINT_ALL)

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_BONUS_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIBFT = $(addprefix $(LIB_PATH), $(LIBFT_NAME))

all:

	@printf "\033[33m"
	@cat logo
	@printf "\033[0m"
	@$(MAKE) -C $(LIB_PATH)
	@$(MAKE) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c

	@mkdir -p $(OBJ_PATH)
	@printf  "\r%-25s\033[34m[$<]\033[0m\n" "$(NAME): $@"
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf "\033[A\033[2K"

$(NAME): $(OBJ) $(HFILENAME) $(LIBFT) Makefile

	@$(CC) $(FLAGS) $(LIBFT) $(OBJ) $(MAIN_NAME) -o $(NAME)
	@printf  "%-25s\033[32m[✔]\033[0m\n" "$(NAME): $@"

bonus: all

	@$(MAKE) $(CHECKER_NAME)

$(CHECKER_NAME): $(CHECKER_FILE) $(OBJ) $(HFILENAME) $(LIBFT) Makefile

	@$(CC) $(FLAGS) $(LIBFT) $(OBJ) $(CHECKER_FILE) -o $(CHECKER_NAME)
	@printf  "%-25s\033[32m[✔]\033[0m\n" "$(CHECKER_NAME): $@"

run: all
	./$(NAME) $(TEST_STACK)

test: bonus

	@printf  "\033[32mresult:\033[0m\n"
	@./$(NAME) $(TEST_STACK)
ifeq (00, $(PRINT_CHECK)$(PRINT_ALL))
	@printf  "\033[32mchecker:\033[0m\n"
	./$(NAME) $(TEST_STACK) | ./$(CHECKER_NAME) $(TEST_STACK)
endif

check: all

	python3 $(PYTHON_CHECKER) $(PWD)/$(NAME)

leaks: bonus

	@printf  "\033[32mLEAKS PushSwap:\033[0m\n"
	@leaks --atExit -- ./$(NAME) $(TEST_STACK)

clean:

	@$(MAKE) -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)
	@printf  "%-25s\033[32m[✔]\033[0m\n" "$(NAME): $@"


fclean: clean

	@$(MAKE) -C $(LIB_PATH) fclean
	@rm -rf $(NAME)
	@rm -rf $(CHECKER_NAME)
	@rm -rf log.txt
	@printf  "%-25s\033[32m[✔]\033[0m\n" "$(NAME): $@"

re: fclean all

.PHONY: clean fclean re bonus test check run
