# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:38:56 by alsiavos          #+#    #+#              #
#    Updated: 2023/11/20 17:05:14 by alsiavos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc 

FLAGS = -Wall -Wextra -Werror

RM = rm -f

FILES = ft_printf.c \
		ft_print_basic.c \
		ft_print_int.c \
		ft_print_usgnint.c \
		ft_print_ptr.c \
		ft_print_hexa.c \

OBJS = $(FILES:.c=.o)

.c.o : 
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJS)
		ar rc $(NAME) $(OBJS)

all :		$(NAME)

clean :
		$(RM) $(OBJS)

fclean : 	clean
		$(RM) $(NAME)

re : fclean all