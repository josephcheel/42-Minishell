#include "../../inc/minishell.h"

int is_builtin(t_minishell *data, char **cmd)
{
	data->cmd_size = ft_cmdsize(cmd);
	if (ft_strncmp(ft_strlwr(cmd[0]), "echo", 5) == 0) // ignores case
	{
		if (data->cmd_size == 1)
			return (ft_echo(cmd, 0));
		else if (data->cmd_size == 2 && ft_strncmp(cmd[1], "-n", 3) == 0)
			return (ft_echo(cmd, 1));
		else
			return (0);
	}
	else if (ft_strncmp(cmd[0], "cd", 3) == 0 && ft_array_size(cmd) >= 1) // only lower caser
		return (ft_cd(data, cmd));
	else if (ft_strncmp(ft_strlwr(cmd[0]), "pwd", 4) == 0) //  ignores case
		return (ft_pwd(cmd));
	else if (ft_strncmp(cmd[0], "export", 7) == 0 && data->cmd_size == 1)
		return (export_builtin(data));
	else if (ft_strncmp(cmd[0], "unset", 6) == 0 && data->cmd_size == 1)
		return (unset_builtin(data));
	else if (ft_strncmp(ft_strlwr(cmd[0]), "env", 3) == 0) //  ignores case
		return (ft_env(data->lstenv));
	else if (ft_strncmp(cmd[0], "exit", 4) == 0 && data->cmd_size >= 1) // only lower caser
		return(exit_builtin(data));
	return (0);
}