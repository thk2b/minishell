NAME = minishell
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./libft/includes -I ./inc

HEAD = $(addprefix inc/, buitin.h minishell.h)
BUILTINS_SRC = $(addprefix builtins/, builtin.c env.c exit.c echo.c cd.c)
LINE_SRC= $(addprefix line/, line_append.c line_delete.c line_free.c line_move.c line_move_word.c line_new.c line_render.c line_resize.c)
SRC = $(addprefix src/, $(BUILTINS_SRC) $(LINE_SRC) error.c init_term.c termcaps_utils.c cursor.c character_handlers.c prompt.c path.c read_cmd.c expand_cmd.c exec_cmd.c main.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -lcurses -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
