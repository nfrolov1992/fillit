/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 18:37:03 by tvanessa          #+#    #+#             */
/*   Updated: 2019/10/10 16:19:23 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_printerr(char *msg, int exit_code, int err_level)
{
	char	*err_level_title[2];

	err_level_title[0] = "Error";
	err_level_title[1] = "Warning";
	if (DEBUG)
	{
		ft_putstr_fd(err_level_title[err_level], 2);
		ft_putstr_fd(" ", 2);
		ft_putnbr_fd(exit_code, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(msg, 2);
		if (err_level == 1)
			return (exit_code);
		else
			exit(exit_code);
	}
	else if (err_level == ERROR)
	{
		ft_putendl_fd(ERRMSG, 2);
		ft_putendl_fd(ERRMSG, 1);
		exit(exit_code);
	}
	return (exit_code);
}
