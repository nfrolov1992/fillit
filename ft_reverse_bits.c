/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:42:14 by tvanessa          #+#    #+#             */
/*   Updated: 2019/10/09 17:58:13 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int		ft_reverse_bits(unsigned int n)
{
	unsigned int c;
	unsigned int r;

	c = sizeof(n) * 8 - 1;
	r = n;
	n >>= 1;
	while (n)
	{
		r <<= 1;
		r |= n & 1;
		n >>= 1;
		--c;
	}
	return (r << c);
}
