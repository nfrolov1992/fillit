/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:35:49 by tvanessa          #+#    #+#             */
/*   Updated: 2019/09/18 15:01:35 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_overflow(long int r, int c, int n)
{
	long int	lm;

	lm = 9223372036854775807L / 10;
	if ((r == lm && c > 7) || r > lm)
	{
		if (n > 0)
			return (-1);
		return (0);
	}
	return (2);
}

int				ft_atoi(const char *str)
{
	long int	res[2];

	res[0] = 0;
	res[1] = 1;
	while (*str)
	{
		if (ft_strchr("+-\t\n\r\v\f ", *str) && res[0] == 0)
		{
			if (*(str - 1) == '-' || *(str - 1) == '+')
				break ;
		}
		else if (*str >= '0' && *str <= '9')
		{
			if (*(str - 1) == '-')
				res[1] = -1;
			if (ft_is_overflow(res[0], (*str - '0'), res[1]) < 2)
				return (ft_is_overflow(res[0], (*str - '0'), res[1]));
			res[0] = res[0] * 10 + (*str - '0');
		}
		else
			break ;
		str++;
	}
	res[0] *= res[1];
	return (res[0]);
}
