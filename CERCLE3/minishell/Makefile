NAME		= minishell
INCLUDE	 = include/
LIBFT	   = libft
SRC_DIR	 = src/
OBJ_DIR	 = obj/
CC		  = cc
CFLAGS	  = -Werror -Wextra -Wall -I $(LIBFT) -I $(INCLUDE) -g
LFLAGS	  = -L$(LIBFT) -lft -lreadline
RM		  = rm -rf

#Sources

CONSTRUCTOR_FILES	=	constructors/execcmd.c\
						constructors/pipecmd.c  constructors/redircmd.c\
						constructors/read_n_write_input.c

EXECUTER_FILES		=	executer/error_exit.c executer/fork_call.c\
						executer/run_cmd.c\
						executer/run_exec.c executer/run_pipe.c\
						executer/run_redir.c executer/wait_pid.c


EXPANDER_FILES		=	expander/expand_array.c expander/expand_dollar.c\
						expander/expand_dollar_split.c\
						expander/expand_str.c\
						expander/expand.c

LEXER_FILES			=	lexer/get_token.c lexer/look_for_token.c lexer/match.c


MEMORY_FILES		=	memory/free_arg_list.c memory/t_free_list.c\
						memory/free_array.c memory/free_cmd_tree.c\
						memory/free_exec.c\
						memory/free_mem.c memory/free_pipe.c\
						memory/free_redir.c memory/free_strvect.c\
						memory/free_env.c memory/free_node.c

BUILTIN_FILES		=	executer/builtins/builtin.c executer/builtins/ft_echo.c\
						executer/builtins/ft_exit.c executer/builtins/ft_pwd.c\
						executer/builtins/ft_cd.c  executer/builtins/ft_env.c\
						executer/builtins/ft_export.c\
						executer/builtins/ft_unset.c

PARSER_FILES		=	parser/parse_cmd_member.c\
						parser/parse_exec.c  parser/parse_redir.c\
						parser/parse_cmd.c\
						parser/parse_pipe.c


SIGNAL_FILES		=	signal/signal.c signal/signal_handle.c

UTIL_FILES			=	utility/find_pair.c utility/get_string.c\
						utility/len_array.c utility/write_to_stderr.c\
						utility/get_path.c utility/insert_back.c\
						utility/replace_char.c utility/secure_write_fd.c \
						utility/is_var_char.c\
						utility/env_function/add_env.c\
						utility/env_function/env_list_to_env_array.c\
						utility/env_function/find_env.c\
						utility/env_function/init_env_shell.c\
						utility/list_function/add_to_list.c\
						utility/list_function/arg_list_to_arg_array.c\
						utility/list_function/bubble_sort_list.c\
						utility/list_function/copy_list.c\
						utility/list_function/list_size.c\
						utility/list_function/list_to_array.c

SRC_FILES   =   main.c
SRC_FILES   +=  $(CONSTRUCTOR_FILES)
SRC_FILES   +=  $(EXECUTER_FILES)
SRC_FILES   +=  $(EXPANDER_FILES)
SRC_FILES   +=  $(LEXER_FILES)
SRC_FILES   +=  $(MEMORY_FILES)
SRC_FILES   +=  $(BUILTIN_FILES)
SRC_FILES   +=  $(PARSER_FILES)
SRC_FILES   +=  $(SIGNAL_FILES)
SRC_FILES   +=  $(UTIL_FILES)


SRC		 =   $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ		 =   $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))


MAKEFLAGS += --no-print-directory

all:	lib $(NAME)

$(NAME):	$(OBJ)
			@${CC} ${OBJ} ${CFLAGS} ${LFLAGS} -o ${NAME}
			@echo "$(NAME) created! -> Project successfully compiled"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

lib:
			@$(MAKE) -s -C $(LIBFT)


clean:
			@$(RM) $(OBJ_DIR)
			@$(MAKE) clean -C $(LIBFT)
			@echo  "Object files deleted!"

fclean:	 clean
			@$(RM) $(NAME)
			@$(MAKE) fclean -C $(LIBFT)
			@echo "All deleted!"

re:		 fclean all

.PHONY:	 all clean fclean re norm lib