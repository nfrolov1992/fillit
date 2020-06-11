/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_bits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:15:23 by tvanessa          #+#    #+#             */
/*   Updated: 2019/10/12 03:37:56 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void				ft_get_tetrims_nums(unsigned long **tetrims)
{
	if (!(*tetrims = (unsigned long*)malloc(sizeof(unsigned long) * 20)))
		return ;
	*tetrims[0] = 52224;
	*(*tetrims + 1) = 34952;
	*(*tetrims + 2) = 61440;
	*(*tetrims + 3) = 36352;
	*(*tetrims + 4) = 57856;
	*(*tetrims + 5) = 51328;
	*(*tetrims + 6) = 17600;
	*(*tetrims + 7) = 59392;
	*(*tetrims + 8) = 11776;
	*(*tetrims + 9) = 50240;
	*(*tetrims + 10) = 35008;
	*(*tetrims + 11) = 50688;
	*(*tetrims + 12) = 27648;
	*(*tetrims + 13) = 19584;
	*(*tetrims + 14) = 35904;
	*(*tetrims + 15) = 58368;
	*(*tetrims + 16) = 19968;
	*(*tetrims + 17) = 35968;
	*(*tetrims + 18) = 19520;
	*(*tetrims + 19) = 0;
}

int						index_of(const void **arr, unsigned long i)
{
	unsigned long	*a;
	int				r;

	a = (unsigned long*)(*arr);
	r = 0;
	while (*a && *a != i)
		a++;
	if (*a == i)
		return (i);
	return (-1);
}

int						convert_to_bit(const char *tetrim, int c)
{
	unsigned long	res;
	unsigned long	*tetrims;

	ft_get_tetrims_nums(&tetrims);
	res = 0;
	while (*tetrim)
	{
		if (*tetrim == c)
			++res;
		if (*(tetrim + 1) != 0)
			res = res << 1;
		++tetrim;
	}
	while (res < MAX_TETRIMINOS && index_of((const void**)&tetrims, res) < 0)
		res = res << 1;
	if (index_of((const void**)&tetrims, res) >= 0)
	{
		ft_memdel((void**)&tetrims);
		return (res);
	}
	ft_memdel((void**)&tetrims);
	return (ft_printerr("Not valid terimino", -2, WARNING));
}
