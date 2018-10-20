NAME = minishell
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = minishell.h
INCLUDES = libft/includes

SRC =\
	main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:
	make fclean -C libft
	rm -f $(NAME)
