/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:16:48 by gmentat           #+#    #+#             */
/*   Updated: 2019/10/10 18:41:04 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_convert_to_str(int tetr)
{
	char			tetrim[17];
	int				value;
	int				i;
	int				j;
	char			*bit_str_tetrim;

	i = 0;
	j = 0;
	while (i < 16)
	{
		value = tetr % 2;
		tetrim[i] = value + 48;
		tetr = tetr / 2;
		i++;
	}
	tetrim[i] = '\0';
	if (!(bit_str_tetrim = ft_strnew(17)))
		return (NULL);
	while (--i >= 0)
	{
		bit_str_tetrim[j] = tetrim[i];
		j++;
	}
	return (bit_str_tetrim);
}
