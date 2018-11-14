/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:38:58 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 22:31:39 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cursor_move(char dir)
{
	if (dir == DIR_UP)
		;
	else if (dir == DIR_DOWN)
		;
	else if (dir == DIR_LEFT)
		return (puttc("le"));
	else if (dir == DIR_RIGHT)
		return (puttc("nd"));
	return (0);
}

int		cursor_move_word(char dir)
{
	if (dir == DIR_UP)
		;
	else if (dir == DIR_DOWN)
		;
	else if (dir == DIR_LEFT)
		return (puttc("le"));
	else if (dir == DIR_RIGHT)
		return (puttc("nd"));
	return (0);
}

int		cursor_putchar(char c)
{
	puttc("im");
	ft_putchar(c);
	puttc("ei");
	return (0);
}

int		cursor_delchar(void)
{
	puttc("le");
	puttc("dc");
	return (0);
}
