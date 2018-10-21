/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:37:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/20 20:42:19 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef int		(*t_builtin_fn)(const char **argv, const char **env);
typedef struct	s_builtin {
	char			*name;
	t_builtin_fn	fn;
}				t_builtin;

int				builtin_echo(const char **argv, const char **env);
int				builtin_cd(const char **argv, const char **env);
int				builtin_env(const char **argv, const char **env);
int				find_builtin(const char **env, const char **command);

#endif
