/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:15:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 23:28:27 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "libft.h"
#include "hash_map.h"
#include <unistd.h>

extern char	**environ;

static int	init(t_hm *vars, char ***path)
{
	char	**pathv;

	MCK((vars = hm_new(100, NULL)), 1);
	MCK(pathv = get_path(environ), 1);
	*path = pathv;
	return (0);
}

static int	teardown(t_hm *vars, char **path)
{
	hm_free(vars, NULL);
	ft_strvdel(path);
	return (0);
}

int			main(void)
{
	t_hm	*vars;
	char	**path;
	char	**cmd;
	int		status;

	status = 0;
	path = NULL;
	vars = NULL;
	init(vars, &path);
	while (1)
	{
		prompt(status);
		if ((cmd = read_cmd()) == NULL)
			continue ;
		status = exec_cmd(path, cmd);
		ft_strvdel(cmd);
		if (status == -1)
			break ;
	}
	teardown(vars, path);
	return (0);
}
