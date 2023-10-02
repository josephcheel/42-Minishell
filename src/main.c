#include "../inc/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_minishell	data;
	char 		*line;

	if (ac != 1 && !av)
		return (1);
	init_env(&data, env);
	//get terminal settings
		if (tcgetattr(STDIN_FILENO, &old_settings) != 0) 
	{
		perror("tcgetattr");
		return (1);
	}

	rl_initialize();//not autorised
	
	//for ctrl + c
		if (signal(SIGINT, signal_handler) == SIG_ERR)
			{
			perror("signal");
			return(1);
			}
	while (1)
	{
		//line = readline();
		//if (!line)
		//	break; //ctrl + d
		data.raw_cmd = display_prompt_msg();
		//line = readline(data.raw_cmd);
		//if (!line)
		//	break; //ctrl + d
		data.last_return_nbr = 0;

		if (ft_strlen(data.raw_cmd) > 0)
			ft_commands(&data);
		else
		{
			if (isatty(STDIN_FILENO))
			write(2, "exit\n", 6);
			exit (EXIT_SUCCESS);
		}
		add_history(line);
		//free(line);
	}
	//restore originial terminal settings
	if (tcsetattr(STDIN_FILENO, TCSANOW, &old_settings) != 0) {
        perror("tcsetattr");
        return 1;
    }

	//ft_freemini(env);
	return (0);
}

