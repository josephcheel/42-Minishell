#include "../inc/minishell.h"


void signal_handler(int sig)
{	
		write(2, "\n", 1);
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay(); 
		 //printf("test");

	(void)sig;
}
