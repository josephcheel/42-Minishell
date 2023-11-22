/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:47:45 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 00:14:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/stat.h> //fstat(), lstat(), and stat() struct
# include <sys/wait.h> // constants for use with waitpid()
# include <unistd.h>
# include <signal.h> //why not usefull?
# include <stddef.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h> //tcsetattr()
# include <sys/errno.h>
# include <fcntl.h>

# include "../libft/inc/libft.h"
# include "environment.h"
# include "variables.h"
# include "split_quotes.h"

# define HEREDOC_FILE ".heredoc"

typedef struct s_status{
	int	status;
}t_status;

typedef struct s_minishell
{
	pid_t			pid;
	int				fd[2];

	int				std_in;
	int				std_out;

	char			**env;
	t_env			*lstenv;

	char			**cmd;
	char			**mul_cmds;

	char			*raw_cmd;
	char			*cleaned_cmd;

	int				nbr_of_cmds;
	int				status;

	char			*infile;
	char			*outfile;

	int				is_append;
	int				is_heredoc;
	int				is_out_heredoc;
	t_list			*in_files;
	t_list			*out_files;
	t_list			*out_append;
	t_list			*heredocs;

	struct termios	old_settings;
	struct termios	new_settings;

}t_minishell;

t_status	g_status;

char	*display_prompt_msg(void);

/* Command Management */
int		ft_commands(t_minishell *data);
int		ft_one_command(t_minishell *data);
int		ft_multiple_commands(t_minishell *data);
char	**ft_separate_cmds(t_minishell *data);
void	ft_init_data_one_cmd(t_minishell *data);
void	ft_init_data_multiple_cmds(t_minishell *data);
/* Command data */
int		ft_cmdsize(char **command);
int		ft_count_commands(char *raw_command);

/* builtins */
int		is_builtin(char **cmd);
int		exec_builtin(t_minishell *data, char **cmd, \
int multiple_cmd, int cmd_nbr);
int		ft_echo(char **cmd, int n_option);
int		ft_pwd(char **cmd);
int		ft_env(t_env *lstenv);
int		ft_export(t_minishell *data, char **cmd);
int		ft_unset(t_minishell *data, char **cmd);
int		ft_exit(char **cmd, int multiple_cmd);
int		ft_cd(t_minishell *data, char **cmd);

//cd utils
int		ft_cd_error_msg(char *arg, char *msg);
int		ft_is_mode_permission_ok(char *file);
void	ft_set_directory(t_env **lstenv, char *variable);

/* signals */
void	signal_handler(int sig);
void	signal_handler_heredoc(int sig);
void	catch_signal(t_minishell *data, int status, int set_status);

/* Parsers */
char	**ft_split_quotes(char *str);
char	**ft_split_pipe(char const *s, int c);

/* Environment variables */

int		init_env(t_minishell *data, char **env);
char	**ft_split_env(char *line);

char	*ft_replace_variable(t_minishell *data, char *variable);
//char	*ft_return_argument(t_minishell *data);

int		ft_is_variable_export(t_minishell *data, char *argument);
int		ft_isvariable(t_env *head, char *id);

/* Expansors */

// Parsin one not-builtin command 
int		commandline(char *str1, char *str2);
char	**command_add(char **route, char *command);
char	*find_command_route_env(t_env *lstenv, char *command);
char	*ft_first_step(t_env *lstenv, char *command, char *line);

int		init_env(t_minishell *data, char **env);
char	**ft_split_env(char *line);

char	*ft_replace_string(char *str, char *replace, char *replacer);
char	*ft_return_argument(t_minishell *data);

char	*ft_get_next_filename(char *raw_cmd);

/* Syntax Errors */
int		ft_syntax_errors(t_minishell *data);
int		ft_check_pipe_sytax(t_minishell *data);
int		ft_check_redir_sytax(char *str);
int		ft_has_valid_quotes(char *str);
void	ft_write_syntax_error(char *str, int i);

// EXECS
void	exec_one(t_minishell *data);
void	exec_multiple(t_minishell *data, char *cmd);

/* Terminal settings */

int		init_term(t_minishell *data);
int		restore_term(t_minishell *data);
int		init_term_fd(t_minishell *data);
int		reset_term_fd(t_minishell *data);
int		close_term_fd(t_minishell *data);

/* Variables */
char	*ft_parse_variables(t_minishell *data);
char	*ft_strchr_variable(char *raw_cmd);

/* Redirections */
void	ft_get_redit_value(char *raw_cmd, t_minishell *data);
void	ft_get_value_infile(t_minishell *data, char *raw_cmd);
void	ft_get_value_outfile(t_minishell *data, char *raw_cmd);
void	ft_get_value_append(t_minishell *data, char *raw_cmd);
void	ft_get_value_heredoc(t_minishell *data, char *raw_cmd);
void	ft_redir_add_list(char *filename, t_list **head);

int		ft_redirect(t_minishell *data);

void	in_file_top(char *filename);
void	in_file_bottom(char *filename);
void	from_file_top(char *filename);
void	from_file_bottom(char *filename);

char	*get_filename(char *raw_cmd, t_minishell *data);

char	*ft_clean_redir_cmd(char *str);

int		ft_permission_files_in(t_list **head);
int		ft_open_files_out(t_minishell *data);

void	ft_heredoc(t_minishell *data);

#endif
