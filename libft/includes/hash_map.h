/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:42:13 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/22 19:51:15 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAP_H
# define HASH_MAP_H
# include "linked_list.h"
# include <stdlib.h>

# define VALIDATE_HASH(i, r) if((i) < 0) return (r)

typedef int		(*t_hm_hash_fn)(const char *key);

typedef struct	s_hm
{
	size_t			arr_size;
	t_llist			**keys;
	t_hm_hash_fn	hash_fn;
}				t_hm;

typedef struct	s_hm_item
{
	const char	*key;
	void		*value;
}				t_hm_item;

int				hash_ascii(const char *str);
t_hm			*hm_new(size_t size, t_hm_hash_fn hash);
t_hm_item		*hm_new_item(const char *key, void *value);
void			*hm_free(t_hm *hm);
int				hm_insert(t_hm *hm, const char *key, void *value);
void			*hm_find(t_hm *hm, const char *key);
void			*hm_remove(t_hm *hm, const char *key);

#endif
