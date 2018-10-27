/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:41:53 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 13:05:57 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		prompt(int status)
{
	if (status)
	{
		ft_putstr(PROMPT_ERR);
		ft_putnbr(status);
		ft_putchar(' ');
	}
	else
		ft_putstr(PROMPT_OK);
	ft_putstr(DEFAULT_PROMPT);
	ft_putstr("\e[0m");
	return (0);
}
