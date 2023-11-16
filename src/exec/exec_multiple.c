#include "../../inc/minishell.h"

void exec_multiple(t_minishell *data, char *raw_cmd)
{
	char *path;
	char **splitted_cmd;
	char *cleaned_cmd;
	int builtin;

	ft_get_redit_value(raw_cmd, data);
	cleaned_cmd = ft_clean_redir_cmd(raw_cmd);
	splitted_cmd = ft_split_quotes(cleaned_cmd);
	builtin = is_builtin(splitted_cmd);
	if (builtin)
	{
		if (ft_redirect(data))
			exit (1);
		exec_builtin(data, splitted_cmd, 1, builtin);
		exit (0);
	}
	// if (exec_builtin(data, splitted_cmd, 1, is_builtin(splitted_cmd)))
	// 	exit(0);
	else if (!raw_cmd[0])
		exit(0);
	else
	{	
		if (!ft_isstralnum(splitted_cmd[0]))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(splitted_cmd[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			exit (127);
		}
		path = find_command_route_env(data->lstenv, data->env, splitted_cmd[0]);
		if (!path)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(data->cmd[0], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			exit(1);
		}
		if (ft_redirect(data))
			exit (1); 
		execve(path, splitted_cmd, data->env);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(splitted_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit (127);
	}
}