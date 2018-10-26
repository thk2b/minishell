/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:06:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 23:22:20 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// #include "hashmap.h"
#include <unistd.h>
#include <limits.h>

#include <printf.h>
extern char **environ;

static void	build_exec_path(char *dst, char *path, char *exec_name)
{
	size_t	path_len;

	path_len = ft_strlen(path);
	ft_strncpy(dst, path, PATH_MAX);
	ft_strlcat(dst, "/", PATH_MAX - path_len);
	ft_strlcat(dst, exec_name, PATH_MAX - path_len - 1);
}

static int	is_path(char *str)
{
	return (ft_strchr(str, '/') != NULL);
}

static char	*get_exec_path(char **path, char **cmd)
{
	size_t	len;
	size_t	i;
	char	exec_path[PATH_MAX];

	if (is_path(cmd[0]))
	{
		if (access(cmd[0], X_OK) == 0)
			return (ft_strdup(cmd[0]));
		else
			return (NULL);
	}
	len = ft_strv_len((const char **)path);
	i = 0;
	while (path[i])
	{
		build_exec_path(exec_path, path[i], cmd[0]);
		if (access(exec_path, X_OK) == 0)
			return (ft_strcjoin(path[i], '/', cmd[0]));
		i++;
	}
	return (NULL);
}

int		exec_cmd(char **path, char **cmd)
{
	// static t_hm	*pathmap;
	char	*exec_path;
	int		status;
	pid_t	pid;

	status = 0;
	if (cmd == NULL || cmd[0] == NULL)
		return (0);
	// if (try_exec_builtin(cmd, &status) == 0)
	// 	return (status);
	if ((exec_path = get_exec_path(path, cmd)) == NULL)
		return (error("command not found", NULL, 1));
	if ((pid = fork()) == -1)
	{
		free(exec_path);
		return (error("exec_cmd", "cannot fork", 1));
	}
	else if (pid == 0)
	{
		if(execve(exec_path, cmd, environ))
			return (error("exec_cmd", "cannot exec", 1));
	}
	else
	{
		free(exec_path);
		if(waitpid(pid, &status, 0) == -1)
			return (error("exec_cmd", "cannot wait", 1));
	}
	return (status);
}
