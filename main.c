/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:15:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 00:26:03 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "hash_map.h"
#include <unistd.h>
#include <printf.h>


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

int			main(void)
{
	t_hm	*vars;
	char	**path;
	char	**cmd;
	int		status;

	status = 0;
	path = NULL;
	vars = NULL;
	init(&vars, &path);
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
