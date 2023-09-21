#include "../inc/minishell.h"

void signal_handler(int sig)
{
    if (sig == SIGINT)
    {
        write(STDERR_FILENO, "\n", 1);
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
    }
}
