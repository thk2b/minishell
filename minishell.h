/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:21:32 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 16:03:07 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/ioctl.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <termcap.h>
# include <curses.h>

# define DEFAULT_PROMPT "<$> "
# define PROMPT_OK "\e[1;32m"
# define PROMPT_ERR "\e[1;31m"

int		init_term(void);
char	**get_path(void);
int		error(const char *predicate, const char *subject, int ret);
int		prompt(int status);
char	**read_cmd(void);
int		expand_cmd(char **cmd);
int		exec_cmd(char **path, char **cmd);

/*
**	cursor.c
*/

# define DIR_UP 'A'
# define DIR_DOWN 'B'
# define DIR_LEFT 'C'
# define DIR_RIGHT 'D'

int		cursor_move(char dir);
int		cursor_putchar(char c);
int		cursor_delchar(void);

/*
**	line.c
*/

# define LINE_BUFSIZE 128

struct			s_cursor
{
	unsigned int	start;
	unsigned int	end;
};

typedef struct	s_line
{
	char			*buf;
	unsigned int	bufsize;
	struct s_cursor	cursor;
}				t_line;

t_line			*line_new(void);
void			line_free(t_line *l);
int				line_append(t_line *l, char c);
int				line_delete(t_line *l);
int				line_move_left(t_line *l);
int				line_move_right(t_line *l);
char			*line_render(t_line *l);

/*
**	termcaps_utils.c
*/

int		puttc(char *name);

#endif
