#include "../inc/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_minishell	data;
	// char envv = {PATH/bin,0};
	if (ac != 1 && !av)
		return (1);
	init_env(&data, env);
	while (1)
	{
		signal(SIGINT, signal_handler); //function to handle signals, SIGINT is ctrl+c, signal_handler is the function to execute
		data.raw_cmd = display_prompt_msg();
		data.last_return_nbr = 0;
		
		if (ft_strlen(data.raw_cmd) > 0)
			ft_commands(&data);
		//ft_freemini(commands);
		// if (ret == -1)
		// 	break;
	}
	//ft_freemini(envv);
	return (0);
}

