/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:40:25 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/21 15:45:06 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <printf.h>

extern char	**environ;
int			main(int ac, const char **av)
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
		eval_command(command, environ);
		free(command);
	}
}
