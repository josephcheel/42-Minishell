#include "../inc/minishell.h"


int init_term(t_minishell *data)
{
	//get terminal settings
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

int	restore_term(t_minishell *data)
{
	//restore originial terminal settings
	if (tcsetattr(STDIN_FILENO, TCSANOW, &data->old_settings) != 0) {
        perror("tcsetattr");
        return 1;
    }
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	data;

	if (ac != 1 && !av)
		return (1);
	init_env(&data, env);
	init_term(&data);
	
	//for ctrl + c
	/*	if (signal(SIGINT, signal_handler) == SIG_ERR)
			{
			perror("signal");
			return(1);
			}
	*/
	
	while (1)
	{
		signal(SIGINT, signal_handler);
		data.raw_cmd = display_prompt_msg();
		if (!data.raw_cmd)
			break; //ctrl + d
		data.status = 0;
		if (!data.raw_cmd)
		{
			if (isatty(STDIN_FILENO))
			write(2, "exit\n", 6);
			exit (EXIT_SUCCESS);
		}
		// is_redirect(data.raw_cmd);
		if (ft_strlen(data.raw_cmd) > 0 && ft_isstralnum(data.raw_cmd))
			ft_commands(&data);

	}
	restore_term(&data);

	//ft_freemini(env);
	return (0);
}

