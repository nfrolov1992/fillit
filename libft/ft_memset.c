/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:14:33 by tvanessa          #+#    #+#             */
/*   Updated: 2019/09/14 18:47:51 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*r;

	r = (unsigned char*)b;
	while (len-- > 0)
	{
		*(r++) = c;
	}
	return (b);
}
