NAME		= libft.a
INCLUDE		= ./
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Werror -Wextra -Wall -g -I $(INCLUDE) 
RM			= rm -rf




SRC_FILES	= 	ft_alloc/ft_bzero.c \
			ft_alloc/ft_calloc.c \
			ft_atob/ft_atof.c \
			ft_atob/ft_atoi.c \
			ft_atob/ft_atol.c \
			ft_atob/ft_itoa.c \

SRC_FILES	+=	ft_is_something/ft_isalnum.c \
			ft_is_something/ft_isalpha.c \
			ft_is_something/ft_isascii.c \
			ft_is_something/ft_isdigit.c \
			ft_is_something/ft_isprint.c \
			ft_is_something/ft_issign.c \
			ft_is_something/ft_isspace.c \
			ft_is_something/ft_str_isalnum.c

SRC_FILES	+=	ft_lst/ft_lstadd_back.c \
			ft_lst/ft_lstadd_front.c \
			ft_lst/ft_lstclear.c \
			ft_lst/ft_lstdelone.c \
			ft_lst/ft_lstiter.c \
			ft_lst/ft_lstlast.c \
			ft_lst/ft_lstmap.c \
			ft_lst/ft_lstnew.c \
			ft_lst/ft_lstsize.c \

SRC_FILES	+=	ft_math/ft_abs.c \
			ft_math/ft_max.c \
			ft_math/ft_min.c \
			ft_mem/ft_memalloc.c \
			ft_mem/ft_memchr.c \
			ft_mem/ft_memcmp.c \
			ft_mem/ft_memcpy.c \
			ft_mem/ft_memmove.c \
			ft_mem/ft_memset.c \

SRC_FILES	+=	ft_printf/ft_printf_1.c \
			ft_printf/ft_printf_2.c \
			ft_printf/ft_printf.c \

SRC_FILES	+=	ft_fprintf/ft_fprintf_1.c\
				ft_fprintf/ft_fprintf.c \
				ft_fprintf/ft_fprintf_2.c \

SRC_FILES	+=	ft_put/ft_print_error.c \
			ft_put/ft_putchar.c \
			ft_put/ft_putchar_fd.c \
			ft_put/ft_putendl.c \
			ft_put/ft_putendl_fd.c \
			ft_put/ft_putnbr_fd.c \
			ft_put/ft_putstr.c \
			ft_put/ft_putstr_fd.c \

SRC_FILES	+=	ft_str/ft_split.c \
			ft_str/ft_split_charset.c \
			ft_str/ft_strchr.c \
			ft_str/ft_strchrset.c \
			ft_str/ft_strcmp.c \
			ft_str/ft_strdup.c \
			ft_str/ft_striteri.c \
			ft_str/ft_strjoin.c \
			ft_str/ft_strlcat.c \
			ft_str/ft_strlcpy.c \
			ft_str/ft_strlen.c \
			ft_str/ft_strlowcase.c \
			ft_str/ft_strmapi.c \
			ft_str/ft_strncmp.c \
			ft_str/ft_strnstr.c \
			ft_str/ft_strrchr.c \
			ft_str/ft_strtrim.c \
			ft_str/ft_substr.c \
			ft_str/ft_tolower.c \
			ft_str/ft_toupper.c \

SRC_FILES	+=	get_next_line/get_next_line.c
			

SRC 		= 	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= 	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

MAKEFLAGS += --no-print-directory


$(NAME):	$(OBJ)
			@ar rc ${NAME} ${OBJ}
			@ranlib ${NAME}
			@echo "$(NAME) created!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean bonus all