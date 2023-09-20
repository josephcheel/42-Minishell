#include "../../inc/minishell.h"

int is_builtin(t_minishell *data)
{
	data->cmd_size = ft_cmdsize(data->cmd);
	if (ft_strncmp(ft_strlwr(data->cmd[0]), "echo", 5) == 0) // ignores case
	{
		if (data->cmd_size == 1)
			return (echo_builtin(data, 0));
		else if (data->cmd_size == 2 && ft_strncmp(data->cmd[1], "-n", 3) == 0)
			return (echo_builtin(data, 1));
		else
			return (0);
	}
	else if (ft_strncmp(data->cmd[0], "cd", 3) == 0 && ft_array_size(data->cmd) == 2) // only lower caser
		return (1);
	else if (ft_strncmp(ft_strlwr(data->cmd[0]), "pwd", 4) == 0 && data->cmd_size == 1) //  ignores case
		return (pwd_builtin(data));
	else if (ft_strncmp(data->cmd[0], "export", 7) == 0 && data->cmd_size == 1)
		return (1);
	else if (ft_strncmp(data->cmd[0], "unset", 6) == 0 && data->cmd_size == 1)
		return (1);
	else if (ft_strncmp(ft_strlwr(data->cmd[0]), "env", 4) == 0 && data->cmd_size == 1) //  ignores case
		return (1);
	else if (ft_strncmp(data->cmd[0], "exit", 5) == 0 && data->cmd_size >= 1) // only lower caser
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}