# ************************************************************************* #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 19:28:21 by vbui              #+#    #+#              #
#    Updated: 2023/11/24 19:33:10 by vbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
#						FONCTIONS DEMANDEES	        						   #
################################################################################

FILESC	= \
	ft_printf.c \

PATH_OPRINTF = ./libft_printf/
PATH_SPRINTF = ./libft_printf/
PATH_IPRINTF = ./libft_printf/
PATH_OLIBFT = ./libft/
PATH_SLIBFT = ./libft/
PATH_ILIBFT = ./libft/
FILESLIBFT = /
	ft_putchar.c/
	ft_putstr.c/
	ft_strcmp.c/
	ft_strdup.c/
	ft_strlen.c/
	ft_strcpy.c/
	ft_memset.c/
	ft_bzero.c/
	ft_memcpy.c/
	ft_memccpy.c/
	ft_memmove.c/
	ft_memchr.c/
	ft_memcmp.c/
	ft_strncpy.c/
	ft_strcat.c/
	ft_strncat.c/
	ft_strlcat.c/
	ft_strchr.c/
	ft_strrchr.c/
	ft_strstr.c/
	ft_strnstr.c/
	ft_strncmp.c/
	ft_atoi.c/
	ft_isalpha.c/
	ft_isdigit.c/
	ft_isalnum.c/
	ft_isascii.c/
	ft_isprint.c/
	ft_toupper.c/
	ft_tolower.c/
	ft_memalloc.c/
	ft_memdel.c/
	ft_strnew.c/
	ft_strdel.c/
	ft_strclr.c/
	ft_striter.c/
	ft_striteri.c/
	ft_strmap.c/
	ft_strmapi.c/
	ft_strequ.c/ ##
	ft_strnequ.c/
	ft_strsplit.c/
	ft_itoa.c/
	ft_strsub.c/
	ft_strjoin.c/
	ft_strtrim.c/
	ft_putendl.c/
	ft_putnbr.c/
	ft_putchar_fd.c/
	ft_putstr_fd.c/
	ft_putendl_fd.c/
	ft_putnbr_fd.c/
	ft_lstnew.c/
	ft_lstdelone.c/
	ft_lstdel.c/
	ft_lstadd.c/
	ft_lstiter.c/
	ft_lstmap.c/
	ft_sqrt.c/
	ft_putwchar.c/
	ft_revstr.c/
	ft_itoa_base.c/
	ft_digitlen.c/
	ft_putwstr.c/
	ft_wstrlen.c/
	ft_wcharlen.c/
	ft_wstrcpy.c/
	ft_wstrcat.c/
	ft_wstrnew.c/
	ft_itoa_base_int.c/
	ft_itoa_base_unsi.c/
	ft_strcapitalize.c/
FILESPRINTF = /
				ft_printf ft_parse_and_store ft_initialise ft_get_arg ft_for_s /
				ft_strjoinfree ft_wstrjoinfree ft_for_p ft_for_d_and_i ft_for_o /
				ft_for_u ft_for_x ft_for_c ft_for_pct ft_first ft_bad_parse /
SLIBFT = $(addprefix $(PATH_SLIBFT), $(addsuffix .c, $(FILESLIBFT)))
OLIBFT = $(addprefix $(PATH_OLIBFT), $(addsuffix .o, $(FILESLIBFT:.c=.o)))
ILIBFT = $(addprefix $(PATH_ILIBFT), libft.h)
SPRINTF = $(addprefix $(PATH_SPRINTF), $(addsuffix .c, $(FILESPRINTF)))
OPRINTF = $(addprefix $(PATH_OPRINTF), $(addsuffix .o, $(FILESPRINTF:.c=.o)))
IPRINTF = $(addprefix $(PATH_IPRINTF), libft_printf.h)

################################################################################
#						CONFIGURATIONS										   #
################################################################################

NAME = libftprintf.a

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OLIBFT) $(OPRINTF)
	ar rcs $(NAME) $(OPRINTF) $(OLIBFT)

$(PATH_OLIBFT)%.o : $(PATH_SLIBFT)%.c $(ILIBFT)
	$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_ILIBFT)

$(PATH_OPRINTF)%.o : $(PATH_SPRINTF)%.c $(IPRINTF)
	$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_IPRINTF)

clean :
	rm -f $(OLIBFT) $(OPRINTF)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

##SRCS = ${FILESC}

##OBJS = ${SRCS:.c=.o}

## BONUS_OBJS		= $(BONUS:.c=.o)

##CC				= cc
##RM				= rm -f
##CFLAGS			= -Wall -Wextra -Werror -I.

##NAME	 		=  libftprintf.a

#all:			$(NAME)

##$(NAME):		$(OBJS)
##				ar rcs $(NAME) $(OBJS)

##clean:
##				$(RM) $(OBJS)

##fclean:			clean
##				$(RM) $(NAME)

##re:				fclean $(NAME)

##bonus:			$(OBJS)
##				ar rcs $(NAME) $(OBJS)

##.PHONY:			all clean fclean re
