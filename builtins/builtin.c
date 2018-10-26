/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 23:32:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/26 12:45:55 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int		builtin(char **av, int *status)
{
	size_t				i;
	static t_builtin	builtins[] = {
		{"exit", b_exit},
		{"cd", b_cd},
		{"env", b_env},
		{"setenv", b_setenv},
		{"unsetenv", b_unsetenv},
	};

	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(av[0], builtins[i].name) == 0)
		{
			*status = builtins[i].fn(av);
			return (0);
		}
		i++;
	}
	return (1);
}
