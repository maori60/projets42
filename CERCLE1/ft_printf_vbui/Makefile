# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 01:20:01 by vbui              #+#    #+#              #
#    Updated: 2024/02/27 01:48:31 by vbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#						FONCTIONS DEMANDEES	        						   #
################################################################################
FILESC = \
				   ft_printf.c\
				   ft_putadress.c\
				   ft_putchar.c\
				   ft_hexa_lower.c\
				   ft_hexa_upper.c\
				   ft_putnbr.c\
				   ft_putstr.c\
				   ft_putunbr.c\
				   ft_strlen.c\

################################################################################
#						CONFIGURATIONS		        						   #
################################################################################

SRCS = ${FILESC}
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

LIB = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -MMD -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		ar -rsc ${LIB} ${OBJS}

all: 	${LIB}

clean:	
		rm -f ${OBJS} ${DEPS}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

-include ${DEPS}

.PHONY: all clean fclean re 