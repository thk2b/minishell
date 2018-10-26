/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strv_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:42:50 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 20:44:27 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strv_dup(const char **strv)
{
	size_t	len;
	size_t	i;
	char	**dup;

	len = ft_strv_len(strv);
	MCK(dup = (char**)malloc(sizeof(char*) * (len + 1)), NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = strv[i];
		i++;
	}
	dup[len] = NULL;
	return (dup);
}
