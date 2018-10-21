/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_escape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 21:00:30 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/20 18:47:55 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*alloc_str(const char *start, const char *end)
{
	char	*s;
	size_t	len;

	len = (end - start);
	if ((s = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(s, start, len);
	s[len] = '\0';
	return (s);
}

static char		**alloc_splits(const char *s, char c, const char *escape)
{
	size_t	count;
	int		escaping;

	count = 1;
	escaping = 0;
	if (ft_strchr(escape, *s))
	{
		escaping = 1;
		s++;
	}
	if (*s == c)
		s++;
	while (*s)
	{
		if (ft_strchr(escape, *s))
		{
			if (!escaping)
				count++;
			escaping = !escaping;
		}
		else if (escaping)
			;
		else if (*s == c && *s && s[1] != c)
			count++;
		s++;
	}
	return ((char**)malloc(count * sizeof(char**)));
}

char			**ft_strsplit_escape(const char *s, char c, const char *escape)
{
	const char	*t;
	const char	*e;
	char		**strv;
	size_t		i;

	t = s;
	i = 0;
	if ((strv = alloc_splits(s, c, escape)) == NULL)
		return (NULL);
	while (s && *s)
	{
		if ((e = ft_strchr(escape, *s)))
		{
			if ((t = ft_strchr(++s, *e)) == NULL)
				strv[i++] = alloc_str(s, s + ft_strlen(s));
			else
				strv[i++] = alloc_str(s, t++);
		}
		else if ((t = ft_strchr(s, (int)c)) == NULL)
			strv[i++] = alloc_str(s, s + ft_strlen(s));
		else
		{
			if (t != s)
				strv[i++] = alloc_str(s, t);
			while (*t && *t == c)
				t++;
		}
		s = t;
	}
	strv[i] = NULL;
	return (strv);
}
