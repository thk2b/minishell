/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:21:32 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 21:33:58 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"

# define DEFAULT_PROMPT "<$> "

char	**get_path(char **env);
int		error(const char *predicate, const char *subject, int ret);
int		prompt(int status);
char	**read_cmd(void);
int		exec_cmd(char **path, char **cmd);

#endif
