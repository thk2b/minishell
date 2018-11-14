/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:42:40 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 23:26:54 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include <unistd.h>
#include <limits.h>

int	b_cd(char **av)
{
	char	*dst;
	char	*curpwd;

	if (av == NULL || av[0] == NULL)
		return (1);
	dst = av[1];
	if (dst == NULL)
	{
		MCK(dst = ft_getenv("HOME"), 1);
	}
	MCK(curpwd = ft_getenv("PWD"), 1);
	if (ft_setenv("OLD_PWD", curpwd, 1))
		return (1);
	if (chdir(dst) == -1)
		return (1);
	if ((curpwd = getcwd(NULL, 0)) == NULL)
		return (1);
	ft_setenv("PWD", curpwd, 1);
	free(curpwd);
	return (0);
}
