#include "../../inc/minishell.h"

int ft_one_command(t_minishell *data)
{
	int status;
	// int redir_type;
	// int code;
		// redir_type = is_redirect(data->raw_cmd);
	signal(SIGINT, SIG_IGN);
	if (is_builtin(data, data->cmd) == 1)
		return (0);
	else
	{
		data->pid = fork();
		if (data->pid == 0)
		{
			signal(SIGINT, signal_handler);
			signal(SIGQUIT, signal_handler);
			exec_one(data);
		}
		
		if (waitpid(data->pid, &status, 0) == -1)
			;
		if (WIFSIGNALED(status))
			catch_signal(status + 128, 1);		
		else if (WIFEXITED(status))
			global_status.status  = WEXITSTATUS(status);
	}
	return (0);
}