
NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBC = ar rcs

SRCS = ft_split.c ft_isdigit.c ft_strlen.c ft_strcmp.c

PRINTF_SRCS = ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_printf.c ft_printf/ft_putstr.c \
			  ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putexa.c \
			  ft_printf/ft_put_adress.c ft_printf/ft_putptr.c

GNL_SRCS =  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS_ALL = $(SRCS) $(SRCSBONUS) $(PRINTF_SRCS) $(GNL_SRCS)

OBJS = $(SRCS_ALL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
