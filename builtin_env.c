/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:42:56 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/21 15:52:21 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include <stdlib.h>

extern char	**environ;

static void	try_free_environ(void)
{
	static int	did_allocate = 0;

	if (did_allocate)
		free(environ);
	else
		did_allocate = 1;
}

int			builtin_env(const char **av)
{
	(void)av;
	ft_putstrv((const char**)environ);
	return (0);
}

int			builtin_setenv(const char **av)
{
	char		**new_env;
	
	if (av[1] == NULL)
		return (1);
	if ((new_env = ft_strv_add((const char **)environ, (char*)av[1])) == NULL)
		return (1);
	try_free_environ();
	environ = new_env;
	return (0);
}

static int	find_env_index(const char *name)
{
	int		i;
	char	*end;

	i = 0;
	while (environ[i])
	{
		if((end = ft_strchr(environ[i], '=')) == NULL)
			return (-1);
		if (ft_strncmp(name, environ[i], end - environ[i]) == 0)
			break ;
		i++;
	}
	if (environ[i] == NULL)
		return (-1);
	return (i);
}

int			builtin_unsetenv(const char **av)
{
	int		i;
	char	**new_env;

	if (av[1] == NULL)
		return (1);
	if((i = find_env_index(av[1])) == -1)
		return (1);
	if (environ[i] == NULL)
		return (1);
	if((new_env = ft_strv_remove(environ, i)) == NULL)
		return (1);
	try_free_environ();
	environ = new_env;
	return (0);
}
