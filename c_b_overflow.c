/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_border_overflow.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:46:41 by gmentat           #+#    #+#             */
/*   Updated: 2019/10/10 19:51:42 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			c_b_overflow(size_t x, size_t y, size_t t_m, size_t m_p)
{
	size_t	border_mask;
	size_t	top_mask;

	border_mask = 4369;
	top_mask = 15;
	if (y + 4 > m_p)
	{
		top_mask = top_mask << ((y + 3 - m_p) * 4);
		if (((t_m | top_mask) != (t_m ^ top_mask)))
			return (1);
	}
	if (x + 4 > m_p)
	{
		border_mask = border_mask << (x + 3 - m_p);
		if (((t_m | border_mask) != (t_m ^ border_mask)))
			return (1);
	}
	return (0);
}
