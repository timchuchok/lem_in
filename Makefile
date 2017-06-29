#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 21:53:23 by vtymchen          #+#    #+#              #
#    Updated: 2017/04/27 21:53:24 by vtymchen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

GCC = gcc -Wall -Wextra -Werror

SRC =	main.c \
		bfs.c \
		check1.c \
		check2.c \
		check3.c \
		check_is.c \
		helper.c \
		list.c \
		move.c \
		parse.c \
		queue.c \
		read.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) printf libf
		$(GCC) -o $(NAME) -Llibft -lft -Lft_printf -lftprintf $(OBJ)

%.o: %.c
	$(GCC) -c -o  $@ $<

libf:
		make -C libft/

printf:
		make -C ft_printf/

clean:
		rm -f $(OBJ)
		make clean -C libft/
		make clean -C ft_printf/

fclean: clean
		make fclean -C libft/
		make fclean -C ft_printf/
		rm -f $(NAME)

re: fclean all