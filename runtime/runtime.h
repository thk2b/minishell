/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:40:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 18:41:39 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUNTIME_H
# define RUNTIME_H
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
int		runtime_free(t_runtime *rt);

#endif
