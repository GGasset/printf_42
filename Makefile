# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggasset- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 16:52:55 by ggasset-          #+#    #+#              #
#    Updated: 2024/11/05 11:09:57 by ggasset-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES = base.c utils.c ft_printf.c
O_FILES = ${patsubst %.c, %.o, ${C_FILES}}

LIBFT_DIR = ./libft
LIBFT_STATIC_LIB = ${LIBFT_DIR}/libft.a

NAME = libftprintf.a

CC_FLAGS = -c -Wall -Wextra -Werror
AR_COMM = ar -rcs ${NAME}




all: ${NAME}

${NAME}: ${O_FILES}
	${AR_COMM} $?

%.o: %.c
	cc ${CC_FLAGS} $?

re: fclean all

fclean: clean
	-rm ${NAME}

clean:
	-rm ${O_FILES}

test:
	cc -g ${C_FILES}

.PHONY: all re fclean clean
