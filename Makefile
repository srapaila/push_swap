NAME = push_swap
NAME_BONUS = checker

COMMON_SRCS = src/parsing.c src/list_utils.c src/check.c src/push_swap.c src/push.c \
				src/reverse_rotate.c src/rotate.c src/swap.c src/utils.c  \
				src/sort_utils.c src/sort_utils2.c src/sort_utils3.c

SRC = src/main.c $(COMMON_SRCS)
SRC_BONUS = src/checker.c $(COMMON_SRCS)

OBJ = $(SRC:src/%.c=obj/%.o)
OBJ_BONUS = $(SRC_BONUS:src/%.c=obj/%.o)
OBJ_DIR = obj

FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(OBJ_DIR) $(LIBFT) $(NAME)

bonus: $(OBJ_DIR) $(LIBFT) $(NAME_BONUS)

$(OBJ_DIR):
	@echo $(CURSIVE)$(GRAY) "Creating obj directory" $(NONE)
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "Compiling $(NAME)" $(NONE)
	@cc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(GREEN)"$(NAME) compiled"$(NONE)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo $(CURSIVE)$(GRAY) "Compiling $(NAME_BONUS)" $(NONE)
	@cc $(FLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo $(GREEN)"$(NAME_BONUS) compiled"$(NONE)

$(LIBFT):
	@echo $(CURSIVE)$(GRAY) "Compiling libft"
	@make -s -C libft
	@echo $(GREEN)"libft compiled"

obj/%.o: src/%.c | $(OBJ_DIR)
	@cc $(FLAGS) -c $< -o $@

clean:
	@echo $(CURSIVE)$(GRAY) "Removing obj files" $(NONE)
	$(RM)  $(OBJ) $(OBJ_BONUS)
	@make -s -C libft clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "Removing $(NAME)" $(NONE)
	$(RM)  $(NAME) $(NAME_BONUS)
	@make -s -C libft fclean
	@echo $(CURSIVE)$(GRAY) "Removing obj directory" $(NONE)
	$(RM) $(OBJ_DIR)

re: fclean all

