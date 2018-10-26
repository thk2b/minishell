/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:57:05 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 18:59:01 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int		error(const char *predicate, const char *subject, int ret)
{
	ft_putstr("minishell: ");
	ft_putstr(predicate);
	if (subject)
	{
		ft_putstr(": ");
		ft_putstr(subject);
	}
	ft_putendl("");
	return (ret);
}
