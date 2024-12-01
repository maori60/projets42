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
FILESLIBFT = ft_putchar ft_putstr ft_strcmp ft_strdup ft_strlen ft_strcpy ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsplit ft_itoa ft_strsub ft_strjoin ft_strtrim ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_sqrt ft_putwchar ft_revstr ft_itoa_base ft_digitlen ft_putwstr ft_wstrlen ft_wcharlen ft_wstrcpy ft_wstrcat ft_wstrnew ft_itoa_base_int ft_itoa_base_unsi ft_strcapitalize
FILESPRINTF = ft_printf ft_parse_and_store ft_initialise ft_get_arg ft_for_s ft_strjoinfree ft_wstrjoinfree ft_for_p ft_for_d_and_i ft_for_o ft_for_u ft_for_x ft_for_c ft_for_pct ft_first ft_bad_parse
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
