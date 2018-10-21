/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:42:56 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/20 20:47:09 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include <stdlib.h>
#include <printf.h>

int	builtin_env(const char **av, const char **env)
{
	size_t	i;

	(void)av;
	printf("A\n");
	i = 0;
	while (env[i])
		ft_putendl(env[i++]);
	return (0);
}
