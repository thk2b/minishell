NAME = minishell
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = minishell.h
INCLUDES = -I libft/includes -I ./ -I ./builtins -I./runtime


BUILTINS_SRC = $(addprefix builtins/, builtin.c env.c exit.c echo.c cd.c)
SRC =\
	$(BUILTINS_SRC)\
	error.c\
	prompt.c\
	path.c\
	read_cmd.c\
	expand_cmd.c\
	exec_cmd.c\
	main.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
