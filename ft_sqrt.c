/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:39:08 by gmentat           #+#    #+#             */
/*   Updated: 2019/10/10 19:39:39 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int			ft_sqrt(size_t n)
{
	size_t	res;

	res = n;
	while ((res = res >> 1) && res * res > n)
		;
	while (res * res < n && ++res)
		;
	if (res * res == n)
		return (res);
	return (0);
}
