/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:33:44 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/28 00:37:20 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include <unistd.h>

static int	expand_empty(char **str)
{
	free(*str);
	MCK(*str = ft_strdup(""), 1);
	return (0);
}

static int	expand_var(char **str)
{
	char	*name_start;
	char	*name_end;
	char	*val;
	char	*new;
	char	*tmp;

	if ((name_start = ft_strchr(*str, '$')) == NULL)
		return (1);
	if ((name_end = ft_strchr(name_start + 1, '$')))
		*name_end = '\0';
	if ((val = getenv(name_start + 1)) == NULL)
		return (expand_empty(str));
	if (name_end)
		*name_end = '$';
	(*str)[name_start - *str] = '\0';
	MCK(new = ft_strjoin(*str, val), 1);
	if (name_end && (tmp = new))
	{
		MCK(new = ft_strjoin(new, name_end), 1);
		free(tmp);
	}
	free(*str);
	*str = new;
	return (0);
}

static int	expand_tilde(char **str)
{
	char	*home;
	char	*new;

	MCK(home = ft_getenv("HOME"), 1);
	new = ft_strjoin(home, (*str) + 1);
	free(*str);
	*str = new;
	return (0);
}

int			expand_cmd(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '~' && (cmd[i][1] == '/' || cmd[i][1] == '\0'))
			expand_tilde(cmd + i);
		while (ft_strchr(cmd[i], '$'))
			if (expand_var(cmd + i))
				break ;
		i++;
	}
	return (0);
}
