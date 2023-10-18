#include "../../inc/minishell.h"

int ft_one_command(t_minishell *data)
{
	int pid;
	int status;

	if (is_builtin(data, data->cmd) == 1)
		return (0);
	else
	{
		pid = fork();
		if (pid == 0)
			exec_one(data);
		if (waitpid(pid, &status, 0) == -1)
			;
		if (WIFEXITED(status))
		{
			data->status = WEXITSTATUS(status);
			// printf("STATUS %d\n", data->status);
		}
	}
	return (0);
}