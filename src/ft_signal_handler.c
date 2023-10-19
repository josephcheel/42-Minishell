#include "../inc/minishell.h"

void signal_handler_parent(int sig)
{
	if (sig == SIGINT)
	{
		// ioctl(STDIN_FILENO, TIOCSTI, "\n"); //Insert the given byte in the input queue. //ERROR: doubles the line 
		
		rl_replace_line("", 0);
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
}

