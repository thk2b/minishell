/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:46:59 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/21 15:23:57 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include <unistd.h>

int		builtin_echo(const char **argv)
{
	int		i;
	ssize_t	status;

	i = 0;
	status = 0;
	while (argv[i])
	{
		status = write(1, argv[i], ft_strlen(argv[i]));
		status += write(1, "\n", 1);
		if (status <= 0)
			return(1);
	}
	return (0);
}
