/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:27:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/20 16:46:35 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "libft.h"

int		find_builtin(const char **argv, const char **env)
{
	static t_builtin	builtins[] = {
		{ "echo", builtin_echo },
		{ "cd", builtin_cd },
		{ NULL, NULL}
	};
	int					i;

	i = 0;
	while (builtins[i].name)
		if (ft_strcmp(builtins[i++].name, argv[0]) == 0)
			return (builtin_cd(argv, env));
	return (1);
}
