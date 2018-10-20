/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:40:23 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/19 19:45:29 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PROMPT "<$>"
# define PROMPT_LEN 3
# define MCK(addr, ret) (if (!addr) return (ret))

int		error(const char *msg, const char *cmd, int ret);
int		prompt();
char	**read_command();
int		eval_command(char **cmd);

#endif
