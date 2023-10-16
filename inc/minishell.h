#ifndef MINISHELL_H
# define MINISHELL_H
#include <sys/types.h> //pthread
#include <sys/stat.h> //fstat(), lstat(), and stat() struct
#include <sys/wait.h> // constants for use with waitpid()
#include <unistd.h>
#include <stdlib.h>
#include <signal.h> //why not usefull?
# include <dirent.h> //format of directory entries (init of a directory)
# include <stddef.h>
#include <stdio.h>
# include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>

# include <termios.h> //tcsetattr()
# include <sys/errno.h>
# include <fcntl.h>

# include "../libft/inc/libft.h"
# include "environment.h"
# include "variables.h"
# include "split_quotes.h"
#include <sys/ioctl.h>


typedef struct s_minishell{

	pid_t	pid;
	int 	fd[2];
	char	**env;
	char	**cmd;
	char	**mul_cmds;
	char	*raw_cmd;


	int		cmd_size;
	int		cmd_and_arguments_size;
	int		nbr_of_cmds;

	int		status;
	// t_list	*lstenv;
	t_env	*lstenv;

	struct termios old_settings;
	struct termios new_settings;
	

}t_minishell;

// struct termios old_settings;

// split bultin, one and multiple cmds
int	ft_commands(t_minishell *data);
int ft_one_command(t_minishell *data);
int	ft_multiple_commands(t_minishell *data);
char **ft_separate_cmds(t_minishell *data);
// Command utils 
int		ft_cmdsize(char **command);
int	ft_count_commands(char *raw_command);


//builtin 
int is_builtin(t_minishell *data, char **cmd);
int echo_builtin(t_minishell *data, int n_option);
int pwd_builtin(t_minishell *data);
int	cd_builtin(t_minishell *data);
int	env_builtin(t_minishell *data);
int export_builtin(t_minishell *data);
int	unset_builtin(t_minishell *data);
int	exit_builtin(t_minishell *data);
//signals
void signal_handler(int sig);

char	**ft_split_quotes(char *str);
char *display_prompt_msg(void);



int	init_env(t_minishell *data, char **env);
char **ft_split_env(char *line);

// t_list	*ft_lstfind_name(t_list **lst, char *find);

char	*ft_replace_variable(t_minishell *data, char *variable);
char *ft_return_argument(t_minishell *data);

int	ft_is_variable_export(t_minishell *data, char *argument);
int	ft_isvariable(t_env *head, char *id);

char	**ft_split_quotes(char *str);

// split bultin, one and multiple cmds
// Command utils 
int		ft_cmdsize(char **command);
int	ft_count_commands(char *raw_command);

// Parsin one not-builtin command 
int		commandline(char *str1, char *str2);
char	**command_add(char **route, char *command);
char	*find_command_route_env(char **env, char *command);

int	init_env(t_minishell *data, char **env);
char **ft_split_env(char *line);

char	*ft_replace_string(char *str, char *replace, char *replacer);
char *ft_return_argument(t_minishell *data);

// EXECS
void exec_one(t_minishell *data);
void exec_multiple(t_minishell *data, char *cmd);
//termios 
int	init_termios(t_minishell *data);

//variables
// char *ft_parse_variables(t_minishell *data);
char	*ft_parse_variables(t_minishell *data);
#endif
