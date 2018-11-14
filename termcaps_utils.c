/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:27:03 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 13:32:07 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		puttc(char *name)
{
	char	buf[32];
	char	*cap;

	MCK(cap = tgetstr(name, (char**)&buf), 1);
	ft_putstr(cap);
	return (0);
}
