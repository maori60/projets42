/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:19:45 by vbui              #+#    #+#             */
/*   Updated: 2024/12/21 00:49:51 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <readline/chardefs.h>
# include <stdbool.h>
# include <dirent.h>
# include <errno.h>
# include "libft.h"
# include <limits.h>

# define MEMO_ERROR	"Error: malloc failed\n"
# define CD_ERR_NOT_ACCESS "minishell: cd:not accessible: Permission denied\n"
# define CD_ERR_NUM_REQUI "minishell: exit: '%s' :numeric argument required\n"
# define ERR_NO_FILE "minishell: '%s':No such file or directory\n"
# define ERR_FILE ":No such file or directory"
# define ERR_EXPORT "minishell: export: '%s': not a valid identifier\n"
# define CMD_NOT_FOUND 		"minishell: %s: command not found\n"
# define GETCWD_ERROR  "minishell: pwd: error retrieving current \
directory: getcwd: %s\n"
# define HEREDOC_FILENAME "/tmp/.heredoc_tmp"

/******************************************************************************
*							GLOBAL VARIABLE  								  *
******************************************************************************/
extern int	g_status;

/*****************************************/
# define WHITESPACES " \t\r\n\v"
# define DOUBLE_QUOTE "\""
# define SINGLE_QUOTE "'"
# define DOLLAR_SIGN "$"

# define QUESTION_MARK "?"

typedef enum e_cmd_types
{
	EXEC = 0,
	REDIR,
	PIPE,
}	t_cmd_type;

typedef enum e_tokens
{
	GREATER = 0,
	LESSER,
	VBAR,
	DOUBLE_GREATER,
	DOUBLE_LESSER,
	WORD_TOKEN,
	BAD_TOKEN,
	END_TOKEN,
}	t_token;

typedef enum e_builtin
{
	NOT_BUILTIN = 0,
	CD,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
}	t_builtin;

typedef enum e_signal_type
{
	SHELL_PARENT,
	EXEC_CHILD,
	HEREDOC,
	WAITING_PARENT,
}	t_signal_type;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_envs
{
	t_env	*head;
	t_env	*tail;
	int		size;
}	t_envs;

typedef struct s_cmd
{
	t_cmd_type	type;
}	t_cmd;

typedef struct s_redir
{
	t_cmd_type	type;
	char		*filename;
	int			mode;
	int			fd;
	t_cmd		*cmd;
}	t_redir_cmd;

typedef struct s_exec
{
	t_cmd_type		type;
	char			*path;
	char			**args;
	char			**env;
	t_redir_cmd		*redirs;
}	t_exec_cmd;

typedef struct s_pipe
{
	t_cmd_type	type;
	t_cmd		*left;
	t_cmd		*right;
}	t_pipe_cmd;

typedef struct s_arg_list
{
	char				*arg;
	int					arg_length;
	struct s_arg_list	*next;
}	t_arg_list;

typedef struct s_shell
{
	t_envs		*envs;
	t_cmd		*parsed_tree;
}	t_shell;

// contructor.c
t_cmd		*redircmd(t_cmd *command, int fd, char *filename, int mode);
t_cmd		*execcmd(char **args, char **env, char *path);
t_cmd		*pipecmd(t_cmd *left, t_cmd *right);
t_cmd		*heredoc_cmd(t_redir_cmd *cmd, char *delimiter);

t_cmd		*hd_perror(t_redir_cmd *cmd, char *str, int fd, char *m);
t_cmd		*hd_stderror(t_redir_cmd *cmd, char *str, int fd, char *m);
t_cmd		*read_n_write_input(t_redir_cmd *cmd, char *delim, int fd);

//lexer
t_token		match(char *symbol, char *end_scan);
t_token		get_token(char **scan_s, char *end_scan, char **token_s,
				char **token_e);
t_token		look_for_token(char **scan_string, char *end_string);

//exec
int			run_exec(t_cmd *cmd, t_shell *shell);
int			run_redir(t_cmd *cmd, t_shell *shell);
int			run_pipe(t_cmd *cmd, t_shell *shell);
int			run_cmd(t_cmd *cmd, t_shell *shell);

void		error_exit(char *s);
pid_t		fork_call(void);
void		safe_exit(char **cmd, t_shell *shell);
int			exec_waitpid(int last_pid);

t_builtin	get_builtin_type(t_exec_cmd *cmd);
int			builtin(t_exec_cmd *cmd, t_builtin i, t_shell *shell);
int			ft_unset(char **cmd, int len, t_shell *shell);
int			ft_env(t_exec_cmd *cmd, t_shell *shell);
int			ft_pwd(t_exec_cmd *cmd, t_shell *shell);
int			ft_export(t_exec_cmd *cmd, int len, t_shell *shell);
int			ft_echo(t_exec_cmd *exec_cmd, t_shell *shell);
int			ft_exit(char **cmd, int len, t_shell *shell);
int			ft_cd(char **cmd, int len, t_shell *shell);

//expander
int			expand_tree(t_cmd *cmd, t_envs *env_list);
int			expand_exec(t_cmd *cmd, t_envs *env_list);
int			expand_redir(t_cmd *cmd, t_envs *env_list);
int			expand_pipe(t_cmd *cmd, t_envs *env_list);

char		**expand_array(char **args, t_envs *env_list);
int			add_char(char *str, char **new_str);
void		expand_str(char *arg, t_arg_list *expanded_list, t_envs *env_list);
int			expand_dollar(char *str, char **new_str, t_envs *env_list);
int			expand_dollar_split(char *str, char **new_str, t_envs *env_list,
				t_arg_list *expanded_list);
t_env		*find_env_and_copy_value(char *str, t_envs *env_list, int *i);
int			expand_env_var(t_envs *env_list, char *str, char **new_str);
int			is_special_char(char c);

//parser
t_cmd		*parse_redir(t_cmd *cmd, char **scan_string, char *end_scan);
t_cmd		*parse_cmd(char *input_string, char **input_progress);
t_cmd		*parse_block(char **scan_pos, char *end_scan);
t_cmd		*parse_pipe(t_cmd *tree, char **scan_pos, char *end_scan);
t_cmd		*parse_cmd_member(char **scan_pos, char *end_scan);
t_cmd		*parse_exec(char **s_p, char *e_s);

//signal
void		ignore_sigquit(void);
void		signal_reset_prompt(int signo);
void		signal_ctlc_heredoc(int sig);
void		reset_signal(pid_t pid, int here_flag);
void		signal_handle(t_signal_type type);
void		default_sigquit(void);
void		exec_interrupt(int sig);

//memory
t_cmd		*free_cmd_tree(t_cmd *cmd);
t_cmd		*free_pipe(t_cmd *cmd);
char		*free_strvect(char **vect);
int			del_node(t_env *del, t_shell *shell);
int			free_list(t_env *head);
int			free_env(t_shell *shell);
void		free_arg_list(t_arg_list *arg_list);
t_cmd		*free_exec(t_cmd *cmd);
t_cmd		*free_redir(t_cmd *cmd);
void		*free_array(char **arg_array);
int			free_node(t_env *node);
char		*free_mem(char **paths, char *str);
void		t_free_list(t_arg_list *head, bool arg_reused);

//util
int			add_env(char *name, char *value, t_shell *shell);
int			unset_var(char *cmd, t_shell *shell);
char		*get_env_value(char *name, t_envs *envs);
int			set_default_env(t_shell *shell);
int			init_env_shell(char **env, t_shell *shell);
char		**env_list_to_env_array(t_envs *env_list);
t_env		*find_env(char *name, t_envs *env_list);
int			find_pair(char *input, char c);
char		*get_string(char *start, char *end);
int			len_array(char **array);
void		write_to_stderr(char *s);
int			secure_write_fd(int fd, char *str);
char		*get_path(char *cmd, t_envs *envs);
int			path_split_append_slash(char **path_split);
int			check_path(char *path, char *arg);
t_env		*copy_list(t_env *head);
char		**list_to_array(t_arg_list *head);
int			list_size(t_arg_list *head);
t_arg_list	*add_to_list(t_arg_list *list, char *arg_start, char *arg_end);
void		bubble_sort_list(t_env *head);
char		**arg_list_to_arg_array(t_arg_list *list);
void		replace_char(char *str, char find, char replace);
void		insert_back(t_arg_list *head, char *arg);
bool		is_var_char(char c);

#endif
