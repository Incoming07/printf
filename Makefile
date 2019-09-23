# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bglover <bglover@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 16:00:15 by bglover           #+#    #+#              #
#    Updated: 2019/09/22 18:18:18 by bglover          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FLAGS = -Wall -Wextra -Werror
NAME = ft_printf.c
#NAME_C = main.c
NAME_O = $(NAME:.c=.o)
#RM = /bin/rm -f

#$(NAME):
#	gcc $(FLAGS) -c $(NAME_C) 
#	gcc $(NAME_O) -L -lft author
	
all: 
#	gcc -g $(NAME) write_fgr.c -o main.1  -L. libft.a
	
#	gcc -g $(NAME) -o ft_printf -L. libft/libftprintf.a
	gcc -g ft_print_float.c -L. libft/libft.a
clean:
	$(RM) $(NAME_O)

fclean:clean
	$(RM) $(NAME_O)

re: fclean all