/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:06:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/28 01:06:32 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <limits.h>
#include <signal.h>

static void	build_exec_path(char *dst, char *path, char *exec_name)
{
	size_t	path_len;

	path_len = ft_strlen(path);
	ft_strncpy(dst, path, PATH_MAX);
	ft_strlcat(dst, "/", PATH_MAX - path_len);
	ft_strlcat(dst, exec_name, PATH_MAX - path_len - 1);
}

static int	validate_exec_path(char *name, int *exists, int show_error)
{
	if (access(name, F_OK) == 0)
	{
		if (access(name, X_OK) == 0)
			return (0);
		*exists = 0;
		if (show_error)
			error("permission denied", NULL, 1);
	}
	else
	{
		*exists = 0;
		if (show_error)
			error("command not found", NULL, 1);
	}
	return (1);
}

static char	*get_exec_path(char **path, char **cmd)
{
	size_t	i;
	char	exec_path[PATH_MAX];
	int		found;

	if (ft_strchr(cmd[0], '/'))
	{
		if (validate_exec_path(cmd[0], &found, 1))
			return (NULL);
		return (ft_strdup(cmd[0]));
	}
	i = 0;
	found = 0;
	while (path && path[i])
	{
		build_exec_path(exec_path, path[i], cmd[0]);
		if (validate_exec_path(exec_path, &found, 0) == 0)
			return (ft_strcjoin(path[i], '/', cmd[0]));
		i++;
	}
	if (found)
		error("permission denied", NULL, 1);
	error("command not found", NULL, 1);
	return (NULL);
}

static int	launch(char *exec_path, char **cmd)
{
	extern char	**environ;
	int			status;
	pid_t		pid;

	status = 0;
	if ((pid = fork()) == -1)
		return (error("cannot fork", NULL, 1));
	else if (pid == 0)
	{
		if (execve(exec_path, cmd, environ))
			return (error("cannot exec", NULL, 1));
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		if (waitpid(pid, &status, 0) == -1)
			return (error("exec_cmd", "cannot wait", 1));
		signal(SIGINT, SIG_DFL);
	}
	return (status);
}

int			exec_cmd(char **path, char **cmd)
{
	extern char	**environ;
	char		*exec_path;
	int			status;

	status = 0;
	if (cmd == NULL || cmd[0] == NULL)
		return (0);
	if ((exec_path = get_exec_path(path, cmd)) == NULL)
		return (1);
	status = launch(exec_path, cmd);
	free(exec_path);
	return (status);
}
