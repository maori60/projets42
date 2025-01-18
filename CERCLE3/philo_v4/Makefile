NAME		=	philo

HEADER		=	./include/

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER) -pthread -O0  #ajout à enlever

SRCS		=	srcs/lib.c \
				srcs/operator.c \
				srcs/threading.c \
				srcs/parsing_init.c \
				srcs/main_utils.c \
				srcs/main.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all