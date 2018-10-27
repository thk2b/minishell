/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:29:58 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 00:06:28 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <unistd.h>

int		ft_putenv(char *str)
{
	extern char	**environ;
	static int	was_allocated = 0;
	char		**new_env;

	MCK(new_env = ft_strv_add(environ, str), -1);
	if (was_allocated)
		ft_strvdel(environ);
	else
		was_allocated = 1;
	environ = new_env;
	return (0);
}
