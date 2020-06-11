# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:27:16 by tvanessa          #+#    #+#              #
#    Updated: 2019/09/19 13:00:06 by tvanessa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = ./
SS = $(S)ft_atoi.c $(S)ft_isascii.c $(S)ft_strcmp.c $(S)ft_strlen.c $(S)ft_strnstr.c $(S)ft_toupper.c $(S)ft_isalnum.c $(S)ft_isprint.c $(S)ft_strcpy.c $(S)ft_strncmp.c $(S)ft_strstr.c $(S)ft_isalpha.c $(S)ft_strcat.c $(S)ft_strdup.c $(S)ft_strncpy.c $(S)ft_tolower.c $(S)ft_strchr.c $(S)ft_strncat.c $(S)ft_strlcat.c $(S)ft_strrchr.c $(S)ft_putnbr.c $(S)ft_putstr.c $(S)ft_putchar.c $(S)ft_bzero.c $(S)ft_isdigit.c $(S)ft_memset.c $(S)ft_memchr.c $(S)ft_memmove.c $(S)ft_memcpy.c $(S)ft_memcmp.c $(S)ft_memccpy.c $(S)ft_putendl.c $(S)ft_putchar_fd.c $(S)ft_putstr_fd.c $(S)ft_putendl_fd.c $(S)ft_putnbr_fd.c $(S)ft_memalloc.c $(S)ft_memdel.c $(S)ft_strnew.c $(S)ft_strdel.c $(S)ft_strclr.c $(S)ft_striter.c $(S)ft_striteri.c $(S)ft_strmap.c $(S)ft_strmapi.c $(S)ft_strequ.c $(S)ft_strnequ.c $(S)ft_strsub.c $(S)ft_strjoin.c $(S)ft_strtrim.c $(S)ft_strsplit.c $(S)ft_itoa.c $(S)ft_lstnew.c $(S)ft_lstadd.c $(S)ft_lstdel.c $(S)ft_lstdelone.c $(S)ft_lstiter.c $(S)ft_lstmap.c $(S)ft_free.c $(S)ft_strtolower.c $(S)ft_strtoupper.c $(S)ft_lstinsert.c $(S)ft_lstappend.c $(S)ft_atol.c $(S)ft_lstprint.c $(S)ft_atoi_recursive.c
H = -I .
NAME = libft.a
CC = gcc
CF = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CF) $(H) -c -o $@ $<

$(NAME): $(SS:.c=.o)
	ar rc $(NAME) $(SS:.c=.o)

clean:
	/bin/rm -f $(SS:.c=.o)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
