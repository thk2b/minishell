/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:55:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 16:01:53 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <printf.h> //tmp

void		handle_interupt(int sig)
{
	(void)sig;
	ft_putchar('\n');
	prompt(0);
}

static int	handle_char(t_line *line, char c); //tmp

static int	handle_arrow(t_line *line, char c)
{
	if (c == 'C')
	{
		line_move_left(line);
		cursor_move(c);
	}
	else if (c == 'D')
	{
		line_move_right(line);
		cursor_move(c);
	}
	return (0);
}

static int	handle_escape(t_line *line)
{
	char	c;

	if (read(0, &c, 1) != 1)
		return (1);
	if (c != 91)
		return (handle_char(line, c));
	if (read(0, &c, 1) != 1)
		return (1);
	if (ft_strchr("ABCD", c))
		return (handle_arrow(line, c));
	return (handle_char(line, c));
}

static int	handle_backspace(t_line *line)
{
	if (line_delete(line))
		return (1);
	return (cursor_delchar());
}

static int	handle_char(t_line *line, char c)
{
	printf("%d,", c);
	if (c == 27)
		return (handle_escape(line));
	if (c == 127)
		return (handle_backspace(line));
	if (c == '\n')
		return (-1);
	line_append(line, c);
	cursor_putchar(c);
	return (0);
}

static int	read_line(int fd, char **linep)
{
	t_line	*line;
	int		ret;
	char	c;

	MCK(line = line_new(), 1);
	while (read(fd, &c, 1))
	{
		if ((ret = handle_char(line, c)) == -1)
			break ;
		else if (ret)
			return (1);
	}
	MCK(*linep = line_render(line), 1);
	line_free(line);
	return (0);
}

char		**read_cmd(void)
{
	char	*line;
	char	**cmd;

	if (init_term())
		return (NULL);
	signal(SIGINT, handle_interupt);
	if (read_line(0, &line))
	{
		error("cannot read", NULL, 0);
		return (NULL);
	}
	signal(SIGINT, SIG_DFL);
	if ((cmd = ft_strsplit_escape(line, ' ', "\"\'")) == NULL)
	{
		error("cannot split", NULL, 0);
		return (NULL);
	}
	free(line);
	return (cmd);
}
