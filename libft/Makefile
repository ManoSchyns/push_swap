NAME = libft.a
SRC = ft_printf.c ft_printf_parsing.c ft_printf_char.c ft_printf_string.c  ft_printf_decimal.c ft_printf_hexa.c ft_printf_pointeur.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	cc -c $(FLAGS) $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all