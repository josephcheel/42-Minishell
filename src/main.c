#include "../inc/minishell.h"

char	*display_prompt_msg(void)
{
	char *str;
	
	str = readline("Minishell ~ % "); // readline won't compile if you don't use -lreadline flag
	if (ft_strlen(str) > 0)
		add_history(str); // to add a history to shell; You can search with up and down arrow keys (↑ ↓) 
	return (str);
}


int	main(int ac, char **av, char **envv) //env?
{
	// char	*input;
	// int		ret;
	// char	**commands;

	//init_envv(ac, av, envv);
	if (ac != 1)
		return (1);
	while (1)
	{
		printf("%s\n", display_prompt_msg());
	 	(void)av;
    	(void)envv;
		//readline("Minishell ~ %% ");
		//signal(SIGINT, signal_handler);
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

