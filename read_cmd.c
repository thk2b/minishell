/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:55:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/12 16:41:12 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <printf.h> //tmp

void		handle_interupt(int sig)
{
	(void)sig;
	ft_putchar('\n');
	prompt(0);
}

static int	init_term(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (1);
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ~ICANON;
	if (tcsetattr(0, TCSAFLUSH, &term) == -1)
		return (1);
	return (0);
}

static int	read_line(int fd, char **line)
{
	char	buf[100] = {0};
	int		cur;

	cur = 0;
	while (read(fd, buf + cur, 1))
	{
		write(1, buf + cur, 1);
		if (buf[cur] == '\n')
			break ;
		cur++;
	}
	return ((*line = ft_strndup(buf, cur)) == NULL);
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
