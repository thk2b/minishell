/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:42:56 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/20 20:50:42 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include <stdlib.h>

int	builtin_env(const char **av, const char **env)
{
	size_t	i;

	(void)av;
	i = 0;
	while (env[i])
		ft_putendl(env[i++]);
	return (0);
}
