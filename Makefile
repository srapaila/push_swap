NAME = push_swap

SRC = src/main.c src/list_utils.c src/check.c src/push_swap.c src/push.c \
		src/reverse_rotate.c src/rotate.c src/swap.c src/utils.c src/utils_sort_five.c \
		src/sort_utils.c src/sort_utils2.c src/sort_utils3.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "Compiling $(NAME)" $(NONE)
	@cc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(GREEN)"$(NAME) compiled"$(NONE)


$(LIBFT):
	@echo $(CURSIVE)$(GRAY) "Compiling libft"
	@make -s -C libft
	@echo $(GREEN)"libft compiled"

$(OBJ): %.o: %.c
#	@echo $(CURSIVE)$(GRAY) "Making files .o" $(NONE)
	@cc $(FLAGS) -c $< -o $@


clean:
	@echo $(CURSIVE)$(GRAY) "Removing files .o" $(NONE)
	$(RM)  $(OBJ)
	@make -s -C libft clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "Removing $(NAME)" $(NONE)
	$(RM)  $(NAME)
	@make -s -C libft fclean

re: fclean all

