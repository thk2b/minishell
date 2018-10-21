/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 21:02:04 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/21 16:41:44 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PROMPT "<$> "
# define PROMPT_LEN 4

int			error(const char *predicate, const char *subject, int ret);
int			prompt();
char		**read_command();
int			eval_command(const char **command);

#endif
