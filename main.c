/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:15:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 22:35:37 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include <unistd.h>

int			main(void)
{
	t_runtime rt;

	runtime_init(&rt);
	env(&rt, NULL);
	// while (1)
	// {
		// prompt(&rt);
		// read_cmd(&rt);
		// exec_cmd(&rt);
	// }
}
