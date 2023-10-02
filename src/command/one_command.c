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
		wait(&pid);
		// kill(0, SIGKILL);
		// if (waitpid(pid, NULL, 0) == -1)
		// 	eft_putstr_fd("ERROR", 2);
	}
	return (0);
}