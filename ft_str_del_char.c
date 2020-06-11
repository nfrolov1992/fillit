/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_del_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:24:06 by gmentat           #+#    #+#             */
/*   Updated: 2019/10/12 04:49:24 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_str_del_char(const char *str, char c)
{
	char	*line;
	int		ci;
	int		i;

	line = NULL;
	ci = 0;
	i = ft_strlen(str);
	while (*(str + ci) && ++ci)
		if (*(str + ci - 1) == c)
			--i;
	if (!(line = ft_strnew(i)))
		ft_printerr("Fail to create new string", -4, ERROR);
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			*(line + i) = *str;
			++i;
		}
		++str;
	}
	return (line);
}
