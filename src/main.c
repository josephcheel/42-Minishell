#include "../inc/minishell.h"

int	main(int ac, char **av, char **envv) //env?
{
	// char	*input;
	// int		ret;
	// char	*raw_command;
	t_minishell	data;

	if (ac != 1 && !av)
		return (1);
	// init_envv(ac, av, envv);
	while (1)
	{
		data.raw_cmd = display_prompt_msg();
		data.last_return_nbr = 0;
		if (ft_strlen(data.raw_cmd) > 0)
			ft_commands(&data, envv);
	
		// signal(SIGINT, signal_handler);
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

