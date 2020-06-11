/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:39:46 by gmentat           #+#    #+#             */
/*   Updated: 2019/10/10 18:30:41 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_valid(char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
			j++;
		if ((!(ft_memchr(".#\n", buf[i], 3))))
			return (0);
		if (buf[i] == '\n' && (i + 1) % 5 != 0)
			return (0);
		i++;
	}
	if (j != 4)
	{
		return (0);
	}
	if (buf[i] != '\n' && buf[i] != '\0')
	{
		return (0);
	}
	return (1);
}
