/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:06:30 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/20 18:10:23 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "get_next_line.h"

char	**read_command(void)
{
	char	*line;
	char	**command;

	if (get_next_line(1, &line) <= 0)
		return (NULL);
	command = ft_strsplit_escape(line, ' ', "\"\'");
	return (command);
}
