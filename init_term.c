/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:24:39 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 20:27:25 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_term(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (1);
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ~ICANON;
	if (tcsetattr(0, TCSAFLUSH, &term) == -1)
		return (1);
	return (0);
}
