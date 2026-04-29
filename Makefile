NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = algo_adaptatif.c \
	   algo_n_racine_n.c \
	   algo_n2.c \
	   algo_nlogn.c \
	   ft_split.c \
	   operations_1.c \
	   operations_2.c \
	   operations_3.c \
	   parse_utils.c \
	   parse.c \
	   push_swap.c \
	   push_swap_utils.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re