/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:42:57 by gmentat           #+#    #+#             */
/*   Updated: 2019/10/10 19:43:16 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_get_map_size(size_t i)
{
	unsigned int	res;

	res = ft_sqrt(i * 4);
	if (res == 0)
		return ((size_t)ft_sqrt(i * 2));
	return ((size_t)res);
}
