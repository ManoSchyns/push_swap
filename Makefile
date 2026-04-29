NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS = algo_adaptatif.c \
	   algo_n_racine_n.c \
	   algo_n2.c \
	   algo_nlogn.c \
	   bench_affichage.c \
	   ft_split.c \
	   operations_1.c \
	   operations_2.c \
	   operations_3.c \
	   parse_utils.c \
	   parse.c \
	   push_swap.c \
	   push_swap_utils.c \
	   pre_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make re -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re