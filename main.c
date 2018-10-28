/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:15:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/28 00:29:35 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "hash_map.h"
#include <unistd.h>

static int	init(t_hm **vars, char ***path)
{
	extern char	**environ;

	MCK(environ = ft_strv_dup(environ), 1);
	MCK((*vars = hm_new(100, NULL)), 1);
	MCK(*path = get_path(environ), 1);
	return (0);
}

static int	teardown(t_hm *vars, char **path)
{
	hm_free(vars, NULL);
	ft_strvdel(path);
	return (0);
}

static void	loop(char **path)
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
		if (expand_cmd(cmd) == 0)
			status = exec_cmd(path, cmd);
		ft_strvdel(cmd);
	}
	ft_strvdel(cmd);
}

int			main(void)
{
	t_hm	*vars;
	char	**path;

	path = NULL;
	vars = NULL;
	init(&vars, &path);
	loop(path);
	teardown(vars, path);
	return (0);
}
