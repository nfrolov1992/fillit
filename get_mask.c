/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mask.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:33:24 by tvanessa          #+#    #+#             */
/*   Updated: 2019/10/12 02:46:33 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		move_up(unsigned int *mask, int offset)
{
	*mask = ft_reverse_bits(*mask);
	*mask >>= 16;
	*mask >>= offset * 4;
	*mask <<= 16;
	*mask = ft_reverse_bits(*mask);
}

static void		move_left(unsigned int *mask, int offset)
{
	while (offset--)
	{
		*mask |= 34952;
		*mask ^= 34952;
		*mask <<= 1;
	}
}

static void		move_right(unsigned int *mask, int offset)
{
	while (offset++)
	{
		*mask |= 4369;
		*mask ^= 4369;
		*mask >>= 1;
	}
}

unsigned int	get_mask(t_tetrim *t, unsigned char x, unsigned char y)
{
	unsigned int	mask;
	int				v_offset;
	int				h_offset;

	mask = t->type;
	v_offset = (y - t->coords[1]);
	h_offset = (x - t->coords[0]);
	if (v_offset > 0)
	{
		move_up(&mask, v_offset);
	}
	else if (v_offset < 0)
		mask >>= v_offset * -1 * 4;
	if (h_offset > 0)
		move_left(&mask, h_offset);
	else if (h_offset < 0)
		move_right(&mask, h_offset);
	return (mask);
}
