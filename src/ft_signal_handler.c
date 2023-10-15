#include "../inc/minishell.h"

void signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n"); //Insert the given byte in the input queue.
		//rl_replace_line("", 0);
		rl_on_new_line();
	}
}

