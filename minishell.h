/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:21:32 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 22:35:46 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "hash_map.h"

typedef struct	s_runtime
{
	t_hm	*env;
	t_hm	*vars;
	char	**path;
	char	**cmd;
	int		status;
}				t_runtime;

int		runtime_init(t_runtime *rt);
int		prompt(t_runtime *rt);
int		read_cmd(t_runtime *rt);
int		exec_cmd(t_runtime *rt);

#endif
