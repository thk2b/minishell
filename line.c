/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:38:35 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 20:17:06 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		line_resize(t_line *l)
{
	char	*buf;
	size_t	old_cursor_end;
	size_t	old_end_size;

	old_end_size = l->bufsize - l->cursor.end + 1; // correct?
	MCK(buf = (char*)malloc(sizeof(char) * (1 + l->bufsize * 2)), 1);
	ft_memcpy(buf, l->buf, l->cursor.start + 1);
	old_cursor_end = l->cursor.end;
	l->cursor.end += l->bufsize;
	l->bufsize *= 2;
	ft_memcpy(buf + l->cursor.end, l->buf + old_cursor_end, old_end_size);
	free(l->buf);
	l->buf = buf;
	return (0);
}

t_line			*line_new(void)
{
	t_line	*l;

	MCK(l = (t_line*)malloc(sizeof(t_line)), NULL);
	l->bufsize = LINE_BUFSIZE;
	MCK(l->buf = (char*)ft_memalloc(sizeof(char) * (l->bufsize + 1)), NULL);
	l->cursor.start = 0;
	l->cursor.end = l->bufsize - 1;
	if (l->cursor.start + 1 >= l->cursor.end)
	{
		if (line_resize(l))
			return (NULL);
	}
	return (l);
}

void			line_free(t_line *l)
{
	free(l->buf);
	free(l);
}

int				line_append(t_line *l, char c)
{
	l->buf[l->cursor.start++] = c;
	if (l->cursor.start == l->cursor.end)
	{
		if (line_resize(l))
			return (1);
	}
	return (0);
}

int				line_delete(t_line *l)
{
	if (l->cursor.start == 0)
		return (1);
	l->buf[l->cursor.start] = '\0';
	l->cursor.start--;
	return (0);
}

int				line_move_right(t_line *l)
{
	if (l->cursor.end == l->bufsize - 1)
		return (1);
	l->buf[++l->cursor.start] = l->buf[l->cursor.end++];
	return (0);
}

int				line_move_left(t_line *l)
{
	if (l->cursor.start == 0)
		return (1);
	l->buf[--l->cursor.end] = l->buf[--l->cursor.start];
	l->buf[l->cursor.start] = '\0';
	return (0);
}

char			*line_render(t_line *l)
{
	char	*s;
	size_t	len;
	size_t	start_len;
	size_t	end_len;

	start_len = l->cursor.start;
	end_len = l->bufsize - l->cursor.end;
	len = start_len + end_len;
	MCK(s = (char*)ft_memalloc(sizeof(char) * (len + 1)), NULL);
	ft_memcpy(s, l->buf, start_len);
	ft_memcpy(s + start_len, l->buf + l->cursor.end, end_len);
	return (s);
}
