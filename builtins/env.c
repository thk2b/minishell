/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:51:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/26 23:59:45 by tkobb            ###   ########.fr       */
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

	if (av == NULL || av[0] == NULL || av[1] == NULL)
		return (1);
	if (ft_strchr(av[1], '='))
		ft_putenv(av[1]);
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
