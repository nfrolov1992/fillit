/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:51:21 by tvanessa          #+#    #+#             */
/*   Updated: 2019/10/12 06:16:44 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_delnode(void *content, size_t size)
{
	ft_memdel(&content);
	size = 0;
}

void		print_tetrims(t_tetrim **arr)
{
	while (*arr)
	{
		ft_putendl(&(*arr)->c);
		ft_putstr("x->");
		ft_putnbr((*arr)->coords[0]);
		ft_putchar(0x0a);
		ft_putstr("y->");
		ft_putnbr((*arr)->coords[1]);
		ft_putchar(0x0a);
		++arr;
	}
}

static void	ft_free_tet_arr(t_tetrim **ts)
{
	while (*ts)
	{
		free(*ts);
		*ts = NULL;
		++ts;
	}
}

void		ft_free_map(t_map **map)
{
	free((*map)->arr);
	(*map)->arr = NULL;
	free(*map);
	map = NULL;
}

int			main(int ac, char **av)
{
	int		fd;
	t_list	*tetrims;
	t_map	*map;

	if (ac == 1)
		ft_printerr("usage: fillit source_file", 0, ERROR);
	if (ac != 2)
		ft_printerr("Too many arguments is passed", 1, ERROR);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_printerr("Fail to open file", 2, ERROR);
	if (get_tetrims(fd, &tetrims) < 0)
	{
		ft_lstdel(&tetrims, ft_delnode);
		ft_printerr("Fail to parse tetriminos map", 7, ERROR);
	}
	if (!(map = fillit_solver(tetrims)))
		ft_printerr("Stop program", 13, WARNING);
	ft_print_result(map->arr, map->size);
	if (close(fd))
		ft_printerr("Fail to close file", 3, ERROR);
	ft_lstdel(&tetrims, ft_delnode);
	ft_free_tet_arr(map->arr);
	ft_free_map(&map);
	exit(0);
}
