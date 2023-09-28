#include "../../inc/minishell.h"

int exec_one(t_minishell *data)
{
	if (execve(find_command_route_env(data->env, data->raw_cmd), data->cmd, NULL) == -1)
		ft_putstr_fd("command not found\n", 2);
	return (0);
}