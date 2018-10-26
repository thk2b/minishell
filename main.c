/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:15:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 19:06:09 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include <unistd.h>

int			main(void)
{
	t_runtime rt;

	if(runtime_init(&rt))
		error("runtime", "cannot init", 1);
	while (1)
	{
		prompt(&rt);
		read_cmd(&rt);
		exec_cmd(&rt);
	}
	runtime_free(&rt);
}
