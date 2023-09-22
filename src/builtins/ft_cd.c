#include "../../inc/minishell.h"\

int	cd_builtin(t_minishell *data)
{
	if (data->cmd[1])
		chdir(data->cmd[1]);
	return (1);
}