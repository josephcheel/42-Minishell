#include "../../inc/minishell.h"

int exec_one(t_minishell *data)
{
	int pid;
	
	pid = fork();
	if (pid == 0)
		execve(find_command_route_env(data->env, data->raw_cmd), data->cmd,NULL);
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		perror("fork error");
	return (0);
}