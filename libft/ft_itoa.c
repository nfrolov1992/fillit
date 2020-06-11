/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:41:10 by tvanessa          #+#    #+#             */
/*   Updated: 2019/09/17 23:44:24 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*r;

	r = NULL;
	if (!(r = ft_strnew(1)))
		return (r);
	if (n < 0)
	{
		r = ft_strcat(r, "-");
		if (n - 1 > n)
			return (ft_strcat(r, "2147483648"));
		n *= -1;
	}
	if (n <= 9)
	{
		n += '0';
		r = ft_strcat(r, (char*)&n);
	}
	else
	{
		r = ft_strcat(r, ft_itoa(n / 10));
		r = ft_strcat(r, ft_itoa(n % 10));
	}
	return (r);
}
