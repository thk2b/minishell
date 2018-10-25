/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hm_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 21:48:20 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/22 22:04:59 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"
#include "libft.h"

static int	cmp_item(void *v_key, void *v_data)
{
	const char		*key;
	t_hm_item		*item;

	key = (const char *)v_key;
	item = (t_hm_item*)v_data;
	return (ft_strcmp(key, item->key) == 0);
}

static void	del_item(void *v_item)
{
	free(v_item);
}

void		*hm_remove(t_hm *hm, const char *key)
{
	int				index;
	t_llist			*item_container;

	VALIDATE_HASH(index = hm->hash_fn(key), NULL);
	item_container = hm->keys[index % hm->arr_size];
	llist_remove(item_container, (void*)key, cmp_item, del_item);
	return (NULL);
}
