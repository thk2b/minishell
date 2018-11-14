/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:21:32 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 21:59:26 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "line.h"
# include <sys/ioctl.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <termcap.h>
# include <curses.h>

# define DEFAULT_PROMPT "<$> "
# define PROMPT_OK "\e[1;32m"
# define PROMPT_ERR "\e[1;31m"

int				init_term(void);
char			**get_path(void);
int				error(const char *predicate, const char *subject, int ret);
int				prompt(int status);
char			**read_cmd(void);
int				expand_cmd(char **cmd);
int				exec_cmd(char **path, char **cmd);

/*
**	character_handlers.c
*/

int				handle_character(t_line *line, char c);
int				handle_arrow(t_line *line, char c);
int				handle_word_arrow(t_line *line, char c);
int				handle_escape(t_line *line);
int				handle_backspace(t_line *line);
int				handle_char(t_line *line, char c);

/*
**	cursor.c
*/

# define DIR_UP 'A'
# define DIR_DOWN 'B'
# define DIR_RIGHT 'C'
# define DIR_LEFT 'D'

int				cursor_move(char dir);
int				cursor_move_word(char dir);
int				cursor_putchar(char c);
int				cursor_delchar(void);

/*
**	termcaps_utils.c
*/

int				puttc(char *name);

#endif
