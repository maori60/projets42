# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 15:00:00 by vbui              #+#    #+#              #
#    Updated: 2025/01/28 12:20:46 by vbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

HEADER		= ./include

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I $(HEADER) -pthread

SRCS		=	srcs/lib.c \
				srcs/operator.c \
				srcs/threading.c \
				srcs/parsing.c \
				srcs/init.c \
				srcs/main_utils.c \
				srcs/main.c \
				srcs/stop_operator.c \
				srcs/finishim.c \

OBJS		= $(SRCS:.c=.o)

RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
