#include "../../inc/minishell.h"

int ft_one_command(t_minishell *data)
{
	int pid;

	if (is_builtin(data) == 1)
		return (0);
	else
	{
		pid = fork();
		if (pid == 0)
			exec_one(data);
		if (waitpid(pid, NULL, 0) == -1)
			ft_putstr_fd("ERROR", 2);
	}
	return (0);
}