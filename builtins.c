/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:27:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/21 15:33:41 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "libft.h"

int		find_builtin(const char **argv)
{
	static t_builtin	builtins[] = {
		{ "echo", builtin_echo },
		{ "cd", builtin_cd },
		{ "env", builtin_env },
		{ "setenv", builtin_setenv },
		{ "unsetenv", builtin_unsetenv },
		{ NULL, NULL}
	};
	int					i;

	i = 0;
	while (builtins[i].name)
		if (ft_strcmp(builtins[i].name, argv[0]) == 0)
			return (builtins[i].fn(argv));
		else
			i++;
	return (-1);
}
