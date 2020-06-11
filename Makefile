# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:27:16 by tvanessa          #+#    #+#              #
#    Updated: 2019/10/12 06:54:09 by tvanessa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = 
SS = $(S)main.c $(S)get_terms.c $(S)ft_is_valid.c $(S)ft_str_del_char.c $(S)ft_convert_to_bits.c $(S)ft_printerr.c $(S)ft_fillit_solver.c $(S)ft_reverse_bits.c $(S)ft_print_result.c $(S)ft_convert_to_str.c $(S)ft_lstcount.c $(S)ft_newtetrim.c $(S)ft_sqrt.c $(S)ft_get_map_size.c $(S)c_b_overflow.c $(S)get_mask.c
H = -I libft/includes -I libft/ -I .
NAME = fillit
CC = clang
CF = -g -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c fillit.h
	$(CC) $(CF) $(H) -c -o $@ $<

$(NAME): libbuild $(SS:.c=.o)
	$(CC) $(CF) $(H) -o $(NAME) $(SS:.c=.o) -L libft/ -lft

libbuild:
	make -C libft/ 

clean:
	make -C libft/ clean 
	/bin/rm -f $(SS:.c=.o)

fclean: clean
	make -C libft/ fclean 
	/bin/rm -f libft.a
	/bin/rm -f $(NAME)

re: fclean all
