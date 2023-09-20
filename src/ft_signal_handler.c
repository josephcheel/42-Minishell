#include "../inc/minishell.h"

void signal_handler(int signo)
{
    if (signo == SIGINT)
    {
        ft_putstr("\n");
        display_prompt_msg();
        signal(SIGINT, signal_handler);
    }
}
