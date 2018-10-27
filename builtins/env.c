/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:51:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/26 23:10:27 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"
#include <unistd.h>


static void	try_free_environ(void)
{
	static int	is_allocated = 0;
	extern char	**environ;

	if (is_allocated)
		free(environ);
	else
		is_allocated = 1;
}

int			b_env(char **av)
{
	extern char	**environ;
	(void)av;
	ft_putstrv(environ);
	return (0);
}

static int	find_env_index(char *name)
{
	extern char	**environ;
	int		i;
	char	*end;

	i = 0;
	while (environ[i])
	{
		if ((end = ft_strchr(environ[i], '=')) == NULL)
			;
		else if (ft_strncmp(environ[i], name, end - environ[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int			b_setenv(char **av)
{
	extern char	**environ;
	char		**new_env;

	if (av == NULL || av[0] == NULL || av[1] == NULL)
		return (1);
	if (ft_strchr(av[1], '=') == NULL)
		return (1);
	b_unsetenv(av);
	MCK((new_env = ft_strv_add(environ, ft_strdup(av[1]))), 1);
	try_free_environ();
	environ = new_env;
	return (0);
}

int			b_unsetenv(char **av)
{
	extern char	**environ;
	int			index;
	char		**new_env;

	if (av == NULL || av[0] == NULL || av[1] == NULL)
		return (1);
	if((index = find_env_index(av[1])) == -1)
		return (1);
	MCK(new_env = ft_strv_remove(environ, index), 1);
	try_free_environ();
	environ = new_env;
	return (0);
}
