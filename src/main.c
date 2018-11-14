/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:15:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 21:15:31 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "libft.h"
#include <unistd.h>

static int	init(char ***path)
{
	extern char	**environ;

	MCK(environ = ft_strv_dup(environ), 1);
	MCK(*path = get_path(), 1);
	return (init_term());
}

static int	teardown(char ***path)
{
	ft_strvdel(*path);
	return (0);
}

static void	check_update_path(char **cmd, char ***path)
{
	if ((ft_strcmp(cmd[0], "setenv") == 0
	|| ft_strcmp(cmd[0], "unsetenv") == 0)
	&& cmd[1] && ft_strcmp(cmd[1], "PATH") == 0)
	{
		if (*path)
			ft_strvdel(*path);
		MCK(*path = get_path(), (void)1);
	}
}

static void	loop(char ***path)
{
	int		status;
	char	**cmd;

	status = 0;
	while (1)
	{
		prompt(status);
		if ((cmd = read_cmd()) == NULL || cmd[0] == NULL)
		{
			if (cmd && cmd[0] == NULL)
				free(cmd);
			status = 0;
			continue ;
		}
		if (ft_strcmp(cmd[0], "exit") == 0)
			break ;
		if (expand_cmd(cmd) == 0 && builtin(cmd, &status) == 0)
			check_update_path(cmd, path);
		else if (cmd)
			status = exec_cmd(*path, cmd);
		ft_strvdel(cmd);
	}
	ft_strvdel(cmd);
}

int			main(void)
{
	char	**path;

	path = NULL;
	init(&path);
	loop(&path);
	teardown(&path);
	return (0);
}
