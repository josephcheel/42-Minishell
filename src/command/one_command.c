#include "../../inc/minishell.h"

int ft_one_command(t_minishell *data)
{
	int pid;
	int status;
	// int code;

	if (is_builtin(data, data->cmd) == 1)
		return (0);
	else
	{
		pid = fork();
		if (pid == 0)
			exec_one(data);
		// signal(SIGQUIT, SIG_IGN);
		// signal(SIGINT, SIG_IGN);
		if (waitpid(pid, &status, 0) == -1)
			;
		// if (WIFSIGNALED(code))
		// {
		// 	printf("%d\n", code);
		// 	code += 129;
		// 	if (code == 130)
		// 		ft_putstr_fd("\n", STDOUT_FILENO);
		// 	if (code == 131)
		// 		ft_putendl_fd("^\\Quit: 3\n", STDOUT_FILENO);
		// }
		if (WIFEXITED(status))
		{
			data->status = WEXITSTATUS(status);
			// printf("STATUS %d\n", data->status);
		}
	}
	return (0);
}