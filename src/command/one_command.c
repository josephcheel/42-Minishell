#include "../../inc/minishell.h"

int ft_one_command(t_minishell *data)
{
	int pid;
	int code;

	if (is_builtin(data) == 1)
		return (0);
	else
	{
		pid = fork();
		if (pid == 0)
			exec_one(data);
		// wait(&pid);
		if (waitpid(pid, &code, 0) == -1)
			;
	}
	return (0);
}