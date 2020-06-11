/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:37:24 by tvanessa          #+#    #+#             */
/*   Updated: 2019/09/16 21:40:53 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((n + 1) == 0 || !(str = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (i < n)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	s1 = ft_strcat(s1, str);
	return (s1);
}
