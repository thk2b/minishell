/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:19:21 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 18:54:54 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <printf.h>

extern char	**environ;

static int	init_env(t_runtime *rt)
{
	int		i;
	char	*sep;
	char	*key;
	char	*value;

	i = 0;
	while (environ[i])
	{
		if ((sep = ft_strchr(environ[i], '=')))
		{
			if ((key = ft_strndup(environ[i], sep - environ[i])) == NULL)
				continue ;
			if ((value = ft_strdup(sep + 1)) == NULL)
			{
				free(key);
				continue ;
			}
			hm_insert(rt->env, key, value);
		}
		i++;
	}
	return (0);
}

static int	init_vars(t_runtime *rt)
{
	return (hm_insert(rt->vars, "PS1", DEFAULT_PROMPT));
}

int			runtime_init(t_runtime *rt)
{
	MCK(rt->env = hm_new(20, NULL), 1);
	MCK(rt->vars = hm_new(20, NULL), 1);
	if (init_env(rt))
		return (1);
	if (init_vars(rt))
		return (1);
	return (0);
}
