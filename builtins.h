/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:37:11 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/21 15:24:25 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef int		(*t_builtin_fn)(const char **argv);
typedef struct	s_builtin {
	char			*name;
	t_builtin_fn	fn;
}				t_builtin;

int				builtin_echo(const char **argv);
int				builtin_cd(const char **argv);
int				builtin_env(const char **argv);
int				builtin_setenv(const char **argv);
int				builtin_unsetenv(const char **argv);
int				find_builtin(const char **argv);

#endif
