/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:07:22 by tvanessa          #+#    #+#             */
/*   Updated: 2019/10/12 06:03:40 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*ft_strndup(const char *s1, size_t n)
{
	char	*r;

	if (!(r = ft_strnew(n)))
		ft_printerr("Fail to create new string", -4, ERROR);
	r = ft_strncpy(r, s1, n);
	return (r);
}

static ssize_t	ft_get_term(int fd, t_list **lst)
{
	ssize_t		ret;
	char		buf[FLT_BUFF_SIZE + 1];
	int			bits;
	char		*str;

	if ((ret = read(fd, buf, FLT_BUFF_SIZE)) > 0)
	{
		buf[ret] = 0x0;
		if (!ft_strstr(buf, "\n\n") && !ft_strstr(buf, "\n\0"))
			return (ft_printerr("Not valid tetrimino", -2, WARNING));
	}
	if (!ft_is_valid(buf))
		return (ft_printerr("Not valid tetrimino", -2, WARNING));
	(*lst)->content = ft_strndup(buf, 20);
	str = ft_str_del_char(buf, 0x0a);
	if ((bits = convert_to_bit(
		(const char *)str, 0x23)) < 0)
		return (ft_printerr("Not valid terimino", -2, WARNING));
	(*lst)->content_size = bits;
	ft_strdel(&str);
	return (ret);
}

int				get_tetrims(int fd, t_list **lst)
{
	int				ret;
	t_list			*clst;

	if (!(*lst = ft_lstnew(NULL, 0)))
		return (ft_printerr("Fail to create root element of list", -1, ERROR));
	clst = *lst;
	while ((ret = ft_get_term(fd, &clst)) == 21)
	{
		clst->next = ft_lstnew(NULL, 0);
		clst = clst->next;
	}
	if (ret < 0)
		return (ft_printerr("Not valid tetriminos map", -3, WARNING));
	return (ret);
}
