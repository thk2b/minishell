/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:51:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 14:47:22 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h" 

static void	*append_to_env(void *v_env, const char *key, void *v_value)
{
	char	**env;
	char	*value;
	size_t	len;
	size_t	keylen;

	env = (char**)v_env;
	value = (char*)v_value;
	keylen = ft_strlen(key);
	len = keylen + ft_strlen(value) + 1;
	MCK(*env = (char*)malloc(sizeof(char) * (len + 1)), NULL);
	ft_strcpy(*env, key);
	(*env)[keylen] = '=';
	ft_strcpy(*env + keylen + 1, value);
	(*env)[len] = '\0';
	return (env + 1);
}

int		env(t_runtime *rt, char **av)
{
	char	**env;

	(void)av;
	if (rt->env == NULL)
		return (1);
	MCK(env = (char**)malloc(sizeof(char*) * rt->env->size), 1);
	env = hm_reduce(rt->env, (void*)env, append_to_env);
	ft_putstrv((const char**)env);
	ft_strvdel(env);
	return (0);
}
