/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:55:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 19:04:05 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"
#include "libft.h"

int	read_cmd(t_runtime *rt)
{
	char	*line;
	char	**cmd;

	if (get_next_line(0, &line) != 1)
		return (error("cannot read", NULL, 1));
	if((cmd = ft_strsplit(line, ' ')) == NULL)
		return (error("cannot split", NULL, 1));
	rt->cmd = cmd;
	return (0);
}
