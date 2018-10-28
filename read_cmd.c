/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:55:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/28 00:00:59 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <signal.h>

void	handle_interupt(int sig)
{
	(void)sig;
	ft_putchar('\n');
	prompt(0);
}

char	**read_cmd(void)
{
	char	*line;
	char	**cmd;

	signal(SIGINT, handle_interupt);
	if (get_next_line(0, &line) != 1)
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
