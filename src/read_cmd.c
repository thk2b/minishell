/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:55:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 23:52:41 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		handle_interupt(int sig)
{
	(void)sig;
	ft_putchar('\n');
	prompt(0);
}

static int	read_line(int fd, char **linep)
{
	t_line	*line;
	ssize_t	nread;
	int		ret;
	char	c;

	MCK(line = line_new(), 1);
	while ((nread = read(fd, &c, 1)) == 1)
	{
		if ((ret = handle_char(line, c)) == -1)
			break ;
		else if (ret)
			return (1);
	}
	if (nread == -1)
		return (1);
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
