/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:11:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/19 19:30:06 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <printf.h>
#include <unistd.h>

int		eval_command(char **command)
{
	char	*exec_path;
	pid_t	child_pid;
	int		stat;

	exec_path = ft_strcjoin("/bin", '/', command[0]);
	if ((child_pid = fork()) == 0)
	{
		if (execve(exec_path, command + 1, NULL))
		{
			
		}
	}
	else
	{
		wait4(child_pid, &stat, 0, NULL);
		free(exec_path);
	}
	return (0);
}
