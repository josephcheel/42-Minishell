#include "../inc/minishell.h"

int	main(int ac, char **av, char **env) //env?
{
	// char	*input;
	// int		ret;
	// char	*raw_command;
	t_minishell	data;

	if (ac != 1 && !av)
		return (1);
	init_env(&data, env);
	while (1)
	{
		
		signal(SIGINT, signal_handler); //function to handle sinals, SIGINT is ctrl+c, signal_handler is the function to execute
		data.raw_cmd = display_prompt_msg();
		data.last_return_nbr = 0;
		// t_list *temp;
		// temp = ft_lstfind_name(&data, "LANG");
		// if (temp)
		// 	printf("NAME: %s VALUE: %s", temp->name, temp->value);
		if (ft_strlen(data.raw_cmd) > 0)
			ft_commands(&data, env);
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

