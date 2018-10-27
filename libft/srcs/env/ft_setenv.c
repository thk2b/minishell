/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:23:59 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 12:48:15 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include <unistd.h>

int		ft_setenv(const char *name, const char *value, int overwrite)
{
	char	*current;
	char	*str;

	current = ft_getenv(name);
	if (current && overwrite == 0)
		return (-1);
	ft_unsetenv(name);
	MCK(str = ft_strcjoin(name, '=', value), -1);
	return (ft_putenv(str));
}
