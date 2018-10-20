/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:44:38 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/19 22:57:15 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <unistd.h>

int		builtin_cd(const char **argv, const char **env)
{
	(void)env;
	if (argv[1] == NULL)
		return (chdir(".."));
	return (chdir(argv[1]));
}
