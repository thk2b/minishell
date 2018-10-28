/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:14:45 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/28 00:51:57 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static char	*find_path(void)
{
	extern char	**environ;
	size_t		len;
	size_t		i;

	len = ft_strv_len(environ);
	i = 0;
	while (i < len)
	{
		if (ft_strncmp("PATH=", environ[i], 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

char		**get_path(void)
{
	char	*path;

	MCK(path = find_path(), NULL);
	return (ft_strsplit(path, ':'));
}
