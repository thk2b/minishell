/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:33:39 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/14 11:30:42 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H
# define LINE_BUFSIZE 48
# include <stdlib.h>

struct			s_cursor
{
	unsigned int	start;
	unsigned int	end;
};

typedef struct	s_line
{
	char			*buf;
	unsigned int	bufsize;
	struct s_cursor	cursor;
}				t_line;

t_line			*line_new(void);
void			line_free(t_line *l);
int				line_resize(t_line *l);
int				line_append(t_line *l, char c);
int				line_delete(t_line *l);
int				line_move_left(t_line *l);
int				line_move_right(t_line *l);
char			*line_render(t_line *l);

#endif
