/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:55:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 15:33:19 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <signal.h>
#include <printf.h>

void	handler(int sig)
{
	(void)sig;
}

char	**read_cmd(void)
{
	char	*line;
	char	**cmd;

	signal(SIGINT, handler);
	if (get_next_line(0, &line) != 1)
	{
		error("cannot read", NULL, 0);
		return (NULL);
	}
	if((cmd = ft_strsplit_escape(line, ' ', "\"\'")) == NULL)
	{
		error("cannot split", NULL, 0);
		return (NULL);
	}
	signal(SIGINT, SIG_DFL);
	free(line);
	return (cmd);
}
