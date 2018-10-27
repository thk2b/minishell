/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:21:32 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/27 13:02:44 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"

# define DEFAULT_PROMPT "<$> "
# define PROMPT_OK "\e[1;32m"
# define PROMPT_ERR "\e[1;31m"

char	**get_path(char **env);
int		error(const char *predicate, const char *subject, int ret);
int		prompt(int status);
char	**read_cmd(void);
int		exec_cmd(char **path, char **cmd);

#endif
