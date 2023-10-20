#include "../inc/minishell.h"

void	catch_signal(int status, int set_status)
{
	if (status == 130)
		ft_putstr_fd("\n", STDOUT_FILENO);
	if (status == 131)
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	if (set_status)
		g_status.status = status;
}


void signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
}

