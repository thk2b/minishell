/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:40:25 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/19 20:09:49 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int		main(int ac, const char **av, const char **env)
{
	const char	**command;

	(void)ac;
	(void)av;
	while (1)
	{
		prompt();
		if ((command = (const char**)read_command()) == NULL)
		{
			error("cannot parse command", NULL, 0);
			continue;
		}
		eval_command(env, command);
		free(command);
	}
}
