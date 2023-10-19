#include "../../inc/minishell.h"

//get terminal settings
int init_term(t_minishell *data)
{

	if (tcgetattr(STDIN_FILENO, &data->new_settings) != 0) 
	{
		perror("tcgetattr");
		return (1);
	}
 	data->old_settings = data->new_settings;
	data->new_settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &data->new_settings) != 0) {
        perror("tcsetattr");
        return 1;
    }
	return (0);
}

//restore originial terminal settings
int	restore_term(t_minishell *data)
{
	
	if (tcsetattr(STDIN_FILENO, TCSANOW, &data->old_settings) != 0) {
        perror("tcsetattr");
        return 1;
    }
	return (0);
}