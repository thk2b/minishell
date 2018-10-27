/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:42:40 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 12:49:08 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include <unistd.h>
#include <limits.h>

int	b_cd(char **av)
{
	char	*curpwd;

	if (av == NULL || av[0] == NULL)
		return (1);
	if (av[1] == NULL)
		return (chdir("~") == -1);
	if ((curpwd = ft_getenv("PWD")) == NULL)
		return (1);
	if (ft_setenv("OLD_PWD", curpwd, 1))
		return (1);
	if (chdir(av[1]) == -1)
		return (1);
	if ((curpwd = getcwd(NULL, 0)) == NULL)
		return (1);
	ft_setenv("PWD", curpwd, 1);
	free(curpwd);
	return (0);
}
