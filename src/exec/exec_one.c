#include "../../inc/minishell.h"

void exec_one(t_minishell *data)
{
	char *path;

	path = find_command_route_env(data->env, data->cmd[0]);
	execve(path, data->cmd, data->env);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data->cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (127);
}