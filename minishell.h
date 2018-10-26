/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:21:32 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 19:05:12 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "runtime.h"

# define DEFAULT_PROMPT "<$> "

int		error(const char *predicat, const char *subject, int ret);
int		prompt(t_runtime *rt);
int		read_cmd(t_runtime *rt);
int		exec_cmd(t_runtime *rt);

#endif
