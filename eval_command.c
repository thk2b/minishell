/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:11:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/19 21:09:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <printf.h>
#include <unistd.h>
#include <limits.h>

static int	is_executable(const char *path, const char *basename)
{
	char	execpath[PATH_MAX];

	ft_strcpy(execpath, path);
	ft_strcat(execpath, "/");
	ft_strcat(execpath, basename);
	if (access(execpath, X_OK) == 0)
		return (1);
	return (0);
}

static char	*find_exec_path(const char **env, const char *name)
{
	int		pi;
	int		pj;
	char	**path; // TODO: without malloc
	char	*exec_path;

	pi = 0;
	while (env[pi])
		if (ft_strstr(env[pi], "PATH="))
			break ;
		else
			pi++;
	if (env[pi] == NULL)
		error("cannot find PATH environment variable", NULL, 0);
	else if ((path = ft_strsplit(env[pi], ':')) == NULL)
		error("cannot split path", NULL, 0);
	else
	{
		pj = 0;
		while (path[pj])
			if (is_executable(path[pj], name))
			{
				exec_path = ft_strcjoin(path[pj], '/', name);
				free(path);
				return (exec_path);
			}
			else
				pj++;
	}
	return (NULL);
}

int			eval_command(const char **env, const char **command)
{
	char	*exec_path;
	pid_t	child_pid;
	int		stat;

	if ((exec_path = find_exec_path(env, command[0])) == NULL)
		return (error("command not found", command[0], 1));
	if ((child_pid = fork()) == -1)
	{
		free(exec_path);
		return (error("cannot fork", NULL, 1));
	}
	else if (child_pid == 0)
	{
		execve(exec_path, (char *const*)command, (char**)env);
		free(exec_path);
		exit(0);
	}
	else
	{
		free(exec_path);
		if (waitpid(child_pid, &stat, 0) == -1)
			return (error("cannot wait4", NULL, 1));
	}
	return (0);
}
