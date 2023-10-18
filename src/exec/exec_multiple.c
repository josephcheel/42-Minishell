#include "../../inc/minishell.h"

void exec_multiple(t_minishell *data, char *cmd)
{
	char *path;
	char **splitted_cmd;

	splitted_cmd = ft_split_quotes(cmd);
	if (is_builtin(data, splitted_cmd))
		exit(0);
	else
	{	
		path = find_command_route_env(data->env, splitted_cmd[0]);
		execve(path, splitted_cmd, data->env);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(splitted_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit (127);
	}
}