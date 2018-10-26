/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:14:45 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 23:02:05 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static char	*find_path(char **env)
{
	size_t	len;
	size_t	i;

	len = ft_strv_len((const char **)env);
	i = 0;
	while (i < len)
	{
		if (ft_str_starts_with("PATH=", env[i]))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char		**get_path(char **env)
{
	char	*path;

	MCK(path = find_path(env), NULL);
	return (ft_strsplit(path, ':'));
}
