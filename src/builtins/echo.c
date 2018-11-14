/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:52:24 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/29 23:04:04 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"

static int	get_n_opt(char **av, int *i)
{
	if (av[1] == NULL)
		return (1);
	if (av[1][0] == '-')
	{
		(*i)++;
		if (av[1][1] == 'n')
			return (0);
	}
	return (1);
}

int			b_echo(char **av)
{
	int		i;
	int		first;
	int		display_nl;

	if (av == NULL || av[0] == NULL)
		return (1);
	i = 1;
	first = 0;
	display_nl = get_n_opt(av, &i);
	if (av[i])
	{
		while (av[i])
		{
			if (first == 0)
				first = 1;
			else
				ft_putchar(' ');
			ft_putstr(av[i]);
			i++;
		}
	}
	if (display_nl)
		ft_putchar('\n');
	return (0);
}
