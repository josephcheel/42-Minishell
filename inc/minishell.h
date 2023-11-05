/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:47:45 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/05 19:17:03 by jcheel-n         ###   ########.fr       */
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

typedef struct s_status{
	int	status;
}t_status;

typedef struct s_minishell{
	pid_t			pid;
	int				fd[2];
	int				std_in;
	int				std_out;
	char			**env;
	char			**cmd;
	char			**mul_cmds;
	char			*raw_cmd;
	char 			*cleaned_cmd;

	int				cmd_size;
	int				cmd_and_arguments_size;
	int				nbr_of_cmds;
	int				status;
	t_env			*lstenv;

	char			*filename;
	char			*infile;
	char			*outfile;
	char			*herdoc;

	struct termios	old_settings;
	struct termios	new_settings;

}t_minishell;

t_status	g_status;

// split bultin, one and multiple cmds
int		ft_commands(t_minishell *data);
int		ft_one_command(t_minishell *data);
int		ft_multiple_commands(t_minishell *data);
char	**ft_separate_cmds(t_minishell *data);
// Command utils 
int		ft_cmdsize(char **command);
int		ft_count_commands(char *raw_command);

//builtin 
int		is_builtin(char **cmd);
int		exec_builtin(t_minishell *data, char **cmd, int multiple_cmd, int cmd_nbr);
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
//signals
void	signal_handler(int sig);
void	catch_signal(int status, int set_status);

char	**ft_split_quotes(char *str);
char	*display_prompt_msg(void);

int		init_env(t_minishell *data, char **env);
char	**ft_split_env(char *line);

char	*ft_replace_variable(t_minishell *data, char *variable);
char	*ft_return_argument(t_minishell *data);

int		ft_is_variable_export(t_minishell *data, char *argument);
int		ft_isvariable(t_env *head, char *id);

char	**ft_split_quotes(char *str);

// split bultin, one and multiple cmds
// Command utils 
int		ft_cmdsize(char **command);
int		ft_count_commands(char *raw_command);

// Parsin one not-builtin command 
int		commandline(char *str1, char *str2);
char	**command_add(char **route, char *command);
char	*find_command_route_env(t_env *lstenv, char **env, char *command);

int		init_env(t_minishell *data, char **env);
char	**ft_split_env(char *line);

char	*ft_replace_string(char *str, char *replace, char *replacer);
char	*ft_return_argument(t_minishell *data);

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
int		ft_redirect(char	*raw_cmd, t_minishell *data); // t_minishell *data changes the data globally? t_minishell data not
void	in_file_top(char *filename);
void	in_file_bottom(char *filename);
void	from_file_top(char *filename);
void	from_file_bottom(char *filename);
char	*get_filename(char *raw_cmd, t_minishell *data);
char *ft_clean_redir_cmd(char *str);

char	**ft_split_pipe(char const *s, int c);

#endif
