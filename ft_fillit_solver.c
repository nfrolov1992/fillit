/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:50:58 by tvanessa          #+#    #+#             */
/*   Updated: 2019/10/12 03:03:44 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim		**fillit_pre_solver(t_list *tetrims_list, size_t tetrims_count)
{
	t_tetrim	**arr;
	t_tetrim	*tetrim;
	char		c;

	arr = NULL;
	c = 0x41;
	if (!(arr = (t_tetrim**)malloc(sizeof(t_tetrim*) * (tetrims_count + 1))))
		ft_printerr("Fail to allocate memmory for t_tetrim array", 9, ERROR);
	while (tetrims_list)
	{
		if (!(tetrim = ft_newtetrim(tetrims_list)))
		{
			ft_free((void**)&arr);
		}
		tetrim->c = c;
		arr[c - 0x41] = tetrim;
		++c;
		tetrims_list = tetrims_list->next;
	}
	arr[tetrims_count] = NULL;
	return (arr);
}

int				check_overflow(t_tetrim **ts, t_tetrim *t, unsigned char x,
unsigned char y)
{
	unsigned int		mask;
	int					xo;
	int					yo;

	while ((*ts)->c < t->c)
	{
		if ((*ts)->coords[0] == x && (*ts)->coords[1] == y)
			return (1);
		xo = (*ts)->coords[0] > x ? (*ts)->coords[0] - x : x - (*ts)->coords[0];
		yo = (*ts)->coords[1] > y ? (*ts)->coords[1] - y : y - (*ts)->coords[1];
		if (xo < 4 && yo < 4)
		{
			mask = (*ts)->type;
			mask = get_mask(*ts, x, y);
			if (mask > 0)
			{
				if ((t->type | mask) != (t->type ^ mask))
					return (1);
			}
		}
		++(ts);
	}
	return (0);
}

int				try_put_tetrim(t_tetrim ***ar, t_tetrim *tet, size_t map_size,
unsigned int i)
{
	size_t		x;
	size_t		y;
	t_tetrim	*t;

	t = *(*ar + i + 1);
	y = 0;
	while (y < map_size)
	{
		x = 0;
		if ((c_b_overflow(x, y, tet->type, map_size)))
			break ;
		tet->coords[1] = y;
		while (x < map_size && (c_b_overflow(x, y, tet->type, map_size)) == 0)
		{
			tet->coords[0] = x;
			if (!(check_overflow(*ar, tet, x, y)))
				if ((t && t->type && try_put_tetrim(ar, t, map_size, i + 1)) ||
				(!(t) || !(t->type)))
					return (1);
			++x;
		}
		++y;
	}
	return (0);
}

t_map			*fillit_solver(t_list *lst)
{
	t_tetrim	**arr;
	size_t		map;
	size_t		tetrims_count;
	t_map		*res;

	if ((tetrims_count = ft_lstcount(lst)) > 26 || tetrims_count < 1)
		ft_printerr("Wrong number of tetrims passed", 14, ERROR);
	if (tetrims_count == 0)
		ft_printerr("No elements in tetrims list", 11, ERROR);
	if ((tetrims_count + 1) == 0)
		ft_printerr("Overflow of tetrims count in tetrims list", 10, ERROR);
	arr = fillit_pre_solver(lst, tetrims_count);
	map = ft_get_map_size(tetrims_count);
	while (!(try_put_tetrim(&arr, *arr, map++, 0)))
	{
		ft_printerr("Fail to find sollution", 12, WARNING);
	}
	if (!(res = (t_map*)malloc(sizeof(t_map))))
		ft_printerr("Fail to allocate memmory for res array", 14, ERROR);
	res->size = map - 1;
	res->arr = arr;
	return (res);
}
