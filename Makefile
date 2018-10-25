NAME = minishell
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = minishell.h
INCLUDES = -I libft/includes -I ./ -I ./builtins


BUILTINS_SRC = $(addprefix builtins/, env.c)
SRC =\
	$(BUILTINS_SRC)\
	runtime_init.c\
	runtime_free.c\
	main.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) -g

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ -g

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
