/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:40:23 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/19 19:08:57 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PROMPT "<$>"
# define PROMPT_LEN 3

int		prompt();
char	**read_command();
int		eval_command(char **cmd);

#endif
