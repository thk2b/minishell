/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_move_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:24:59 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/13 22:30:19 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

int	line_move_right_word(t_line *l)
{
	while (ISWS(l->buf[l->cursor.start]))
		if (line_move_right(l))
			return (1);
	return (0);
}

int	line_move_left_word(t_line *l)
{
	while (ISWS(l->buf[l->cursor.start]))
		if (line_move_left(l))
			return (1);
	return (0);
}

