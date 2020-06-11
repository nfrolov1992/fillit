/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:24:38 by gmentat           #+#    #+#             */
/*   Updated: 2019/10/12 06:32:53 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_pow(int nb, int p)
{
	int	res;

	res = 1;
	while (p-- > 0)
		res *= nb;
	return (res);
}

void		ft_set_tetrim_on_map(size_t map, t_tetrim *arr, char **res)
{
	char	*t_map;
	int		a[2];
	int		j;

	a[0] = 0;
	a[1] = 0;
	t_map = ft_convert_to_str((arr)->type);
	j = arr->coords[1] * map + arr->coords[0];
	while (*t_map)
	{
		if (a[0] > 3)
		{
			a[1] += map;
			j = (arr->coords[1] * map + arr->coords[0]) + a[1];
			a[0] = 0;
		}
		if (*t_map == '1')
			(*res)[j] = arr->c;
		++t_map;
		++j;
		++a[0];
	}
	t_map -= 16;
	ft_strdel(&t_map);
}

char		*ft_set_tetrims_on_map(t_tetrim **arr, size_t map)
{
	char	*res;

	if (!(res = ft_strnew((size_t)(ft_pow(map, 2)))))
		return (0);
	ft_memset(res, '.', (size_t)(ft_pow(map, 2)));
	while (*arr)
	{
		ft_set_tetrim_on_map(map, *arr, &res);
		++arr;
	}
	return (res);
}

void		ft_print_result(t_tetrim **arr, size_t map_size)
{
	char	*result_map;
	char	*final_map;
	int		i;

	result_map = ft_set_tetrims_on_map(arr, map_size);
	if (!(final_map = ft_strnew((size_t)(ft_pow(map_size, 2) + map_size))))
		ft_printerr("Fail to create new string", -4, ERROR);
	i = map_size;
	while (i)
	{
		ft_strncpy(final_map, result_map, map_size);
		*(final_map + map_size) = 0x0a;
		final_map += map_size + 1;
		result_map += map_size;
		--i;
	}
	result_map -= ft_pow(map_size, 2);
	final_map -= (ft_pow(map_size, 2) + map_size);
	ft_putstr(final_map);
	ft_strdel(&result_map);
	ft_strdel(&final_map);
}
