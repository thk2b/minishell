/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:30:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 15:42:03 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		runtime_free(t_runtime *rt)
{
	hm_free(rt->env, NULL);
	// hm_free(rt->vars, NULL);
	// ft_strvdel(rt->path);
	// ft_strvdel(rt->cmd);
	while(1);
	return (0);
}
