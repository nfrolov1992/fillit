/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:12:57 by tvanessa          #+#    #+#             */
/*   Updated: 2019/10/12 06:49:28 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define FLT_BUFF_SIZE	21
# define ERRMSG			"error"
# define DEBUG			0
# define ERROR			0
# define WARNING		1
# define MAX_TETRIMINOS	61440

typedef struct		s_tetrim
{
	unsigned int	coords[2];
	char			c;
	int				type;
}					t_tetrim;

typedef struct		s_map
{
	size_t			size;
	t_tetrim		**arr;
}					t_map;

t_tetrim			*ft_newtetrim(t_list *lst);
int					get_tetrims(int fd, t_list **lst);
/*
** Print error massege to error output and returns code of error if err_level is
** `WARNING` or exit with `exit_code` if err_level is `ERROR` or `DEBUG` is 0.
** @params: {char *msg} Error massege to print,
** if `DEBUG` is 0 than message will print from `ERRMSG`.
** @params: {int exit_code} code of error.
** @params: {int err_level} Error level is `WARNING` if program
** must continue execution or `ERROR` if it must stop execution.
** @return: {int} Returns exit_code if `DEBUG` equals to 1
** and if err_level is `WARNING`.
*/
int					ft_printerr(char *msg, int exit_code, int err_level);
/*
** Checks that tetriminos desription in file is valid.
** @params: {char *buf} String representation of tetrimino.
** @return: {int} 1 if description is valid and 0 if not.
*/
int					ft_is_valid(char *buf);
/*
** Convert string to interger, in representation that `c` character
** is becomes 1 and other else becoms 0
** @params: {const char *str} String to convert
** @params: {char c} Character to search
** @return: {int} Resulting interger
*/
int					convert_to_bit(const char *str, int c);
/*
** Delete all chars, that passed as second parameter
** from string and return "fresh" string
** @params:	{const char *str} String from where need to delete characters
** @params: {char c} Character to delete
** @return: {char *} New string with out character, that need to  delete,
** if character isn't ocures function returns the same string
*/
char				*ft_str_del_char(const char *str, char c);
/*
** Try to solve the task, if there no solutions returns NULL,
** otherewise returns the array of t_tetrims structs
** @params: {t_list *tetrims_list} List of tetriminos
** @return: {t_tetrim**} Array of t_tetrim structs
*/
t_map				*fillit_solver(t_list *tetrims_list);
/*
** Prints solved task
*/
void				ft_print_result(t_tetrim **arr, size_t map_size);
/*
** Take numbers tetromines in int and convert in string
** @params:	{int tetr} number tetromines in integer
** @return: {char *} New string with character,
** being a field of a figure tetromines
*/
char				*ft_convert_to_str(int tetr);
/*
** Reverse bits in number, passed as argument,
** and returns new number with reversed bits
** @params: {unsigned int n} Value, that need to reverse bits
** @return: {unsigned int} New value
*/
unsigned int		ft_reverse_bits(unsigned int n);
size_t				ft_lstcount(const t_list *lst);
unsigned int		ft_sqrt(size_t n);
size_t				ft_get_map_size(size_t i);
int					c_b_overflow(size_t x, size_t y, size_t t_m, size_t m_p);
unsigned int		get_mask(t_tetrim *t, unsigned char x, unsigned char y);

#endif
