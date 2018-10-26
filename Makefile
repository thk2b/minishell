NAME = minishell
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = minishell.h
INCLUDES = -I libft/includes -I ./ -I ./builtins -I./runtime


BUILTINS_SRC = $(addprefix builtins/, env.c)
RUNTIME_SRC = $(addprefix runtime/, free.c init.c)
SRC =\
	error.c\
	$(BUILTINS_SRC)\
	$(RUNTIME_SRC)\
	prompt.c\
	read_cmd.c\
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
