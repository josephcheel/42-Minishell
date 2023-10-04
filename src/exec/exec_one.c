#include "../../inc/minishell.h"

void exec_one(t_minishell *data)
{
	execve(find_command_route_env(data->env, data->raw_cmd), data->cmd, data->env);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data->cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (127);
}