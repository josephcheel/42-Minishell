#include "../inc/minishell.h"

int	main(int ac, char **av, char **envv) //env?
{
	// char	*input;
	// int		ret;
	// char	*raw_command;
	t_minishell	data;

	if (ac != 1 && !av)
		return (1);
	//init_envv(ac, av, envv);
	while (1)
	{
		signal(SIGINT, signal_handler); //function to handle sinals, SIGINT is ctrl+c, signal_handler is the function to execute
		data.raw_cmd = display_prompt_msg();
		if (data.raw_cmd)
			ft_commands(&data, envv);
	
		 
		//get_input(&input);
		// if (ft_isemptystr(input, 1))
		// {
		// 	free(input);
		// continue;
		// }
		//commands = ft_strsplit(input, ';');
		//free(input);
		//ret = exec_commands(commands);
		//ft_freestrarr(commands);
		// if (ret == -1)
		// 	break;
	}
	//ft_freestrarr(g_envv);
	return (0);
}
