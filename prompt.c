/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:41:53 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 18:54:29 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		prompt(t_runtime *rt)
{
	char	*prompt;

	if ((prompt = hm_find(rt->vars, "PS1")))
		ft_putstr(prompt);
	else
		ft_putstr(DEFAULT_PROMPT);
	return (0);
}
