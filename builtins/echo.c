/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:52:24 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 12:56:59 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"

int		b_echo(char **av)
{
	char	**words;
	int		i;


	if (av == NULL || av[0] == NULL)
		return (1);
	if (av[1])
	{
		MCK(words = ft_strsplit_escape(av[1], ' ', "\"\'"), 1);
		i = 0;
		while (words[i])
		{
			if (i)
				ft_putchar(' ');
			ft_putstr(words[i]);
		}
	}
	ft_putchar('\n');
	return (0);
}
