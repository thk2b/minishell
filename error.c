/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:39:02 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/19 20:00:06 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int		error(const char *msg, const char *cmd, int ret)
{
	ft_putstr("minishell: ");
	if (cmd)
	{
		ft_putstr(cmd);
		ft_putstr(": ");
	}
	ft_putendl(msg);
	return (ret);
}
