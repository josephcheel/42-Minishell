#include "../inc/minishell.h"

int	main(int ac, char **av, char **envv)
{
	t_minishell	data;
	// char envv = {PATH/bin,0};
	if (ac != 1 && !av)
		return (1);
	// init_envv(ac, av, envv);
	while (1)
	{
		data.raw_cmd = display_prompt_msg();
		data.last_return_nbr = 0;
		signal(SIGINT, signal_handler); //function to handle signals, SIGINT is ctrl+c, signal_handler is the function to execute
		if (ft_strlen(data.raw_cmd) > 0)
			ft_commands(&data, envv);
		//ft_freemini(commands);
		// if (ret == -1)
		// 	break;
	}
	//ft_freemini(envv);
	return (0);
}

