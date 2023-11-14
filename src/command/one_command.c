#include "../../inc/minishell.h"

int	ft_one_command(t_minishell *data)
{
	int status;
	int builtin;

	signal(SIGINT, SIG_IGN);
	builtin = is_builtin(data->cmd);
	if (builtin)
	{
		if (ft_redirect(data))
			return (1);
		exec_builtin(data, data->cmd, 0, builtin);
		return (0);
	}
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
			catch_signal(data, status + 128, 1);
		else if (WIFEXITED(status))
			g_status.status = WEXITSTATUS(status);
	}
	return (0);
}
