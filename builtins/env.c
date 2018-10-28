/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:51:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/28 00:04:04 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"
#include "env.h"
#include <unistd.h>

int			b_env(char **av)
{
	extern char	**environ;
	char		*str;
	int			i;
	int			status;

	if (av[1])
	{
		i = 1;
		status = 0;
		while (av[i])
		{
			str = ft_getenv(av[i++]);
			if (str == NULL)
				status = 1;
			else
				ft_putendl(str);
		}
		return (status);
	}
	ft_putstrv(environ);
	return (0);
}

int			b_setenv(char **av)
{
	extern char	**environ;
	char		*tmp;

	if (av == NULL || av[0] == NULL || av[1] == NULL)
		return (1);
	if (ft_strchr(av[1], '='))
	{
		MCK(tmp = ft_strdup(av[1]), 1);
		ft_putenv(tmp);
	}
	else if (av[2])
		ft_setenv(av[1], av[2], 1);
	else
		return (1);
	return (0);
}

int			b_unsetenv(char **av)
{
	extern char	**environ;
	int			status;
	int			i;

	if (av == NULL || av[0] == NULL || av[1] == NULL)
		return (1);
	status = 0;
	i = 1;
	while (av[i])
		status = (ft_unsetenv(av[i++]) == 1) || status;
	return (status);
}
