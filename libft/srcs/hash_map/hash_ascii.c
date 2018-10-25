/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 00:21:55 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/22 19:48:12 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"
#include "libft.h"

int		hash_ascii(const char *str)
{
	int		hash;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	hash = 1;
	while (str[i])
	{
		hash = (hash * (len - i + 1) * str[i]);
		i++;
	}
	return (hash);
}
