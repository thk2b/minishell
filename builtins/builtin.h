/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:52:21 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/26 12:41:49 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "minishell.h"

typedef int		(*t_builtin_fn)(char **av);
typedef struct	s_builtin
{
	char			*name;
	t_builtin_fn	fn;
}				t_builtin;

int			b_env(char **av);
int			b_setenv(char **av);
int			b_unsetenv(char **av);
int			b_exit(char **av);
int			b_cd(char **av);
int			builtin(char **av, int *status);

#endif
