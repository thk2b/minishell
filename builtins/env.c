/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:51:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 12:08:54 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"
#include "env.h"
#include <unistd.h>

int			b_env(char **av)
{
	extern char	**environ;
	(void)av;
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

	if (av == NULL || av[0] == NULL || av[1] == NULL)
		return (1);
	return (ft_unsetenv(av[1]) == -1);
}
