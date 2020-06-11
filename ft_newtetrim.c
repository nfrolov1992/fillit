/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtetrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:34:55 by gmentat           #+#    #+#             */
/*   Updated: 2019/10/10 19:35:08 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim		*ft_newtetrim(t_list *lst)
{
	t_tetrim	*tetrim;

	tetrim = NULL;
	if (!(tetrim = (t_tetrim*)malloc(sizeof(t_tetrim))))
	{
		ft_printerr("Fail create new tetrim", 12, WARNING);
		return (NULL);
	}
	tetrim->coords[0] = 0;
	tetrim->coords[1] = 0;
	tetrim->c = 0;
	tetrim->type = lst->content_size;
	return (tetrim);
}
