/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:11:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/19 19:50:38 by tkobb            ###   ########.fr       */
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
	if ((child_pid = fork()) == -1)
	{
		free(exec_path);
		return (error("cannot fork", NULL, 1));
	}
	else if (child_pid == 0)
	{
		execve(exec_path, command + 1, NULL);
		free(exec_path);
		exit(0);
	}
	else
	{
		free(exec_path);
		if (wait4(child_pid, &stat, 0, NULL) == -1)
			return (error("cannot wait4", NULL, 1));
	}
	return (0);
}
