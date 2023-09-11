#include "minishell.h"

int	main(int ac, char **av, char **envv) //env?
{
	char	*input;
	int		ret;
	char	**commands;

	init_envv(ac, av, envv);

	while (1)
	{
		display_prompt_msg();
		signal(SIGINT, signal_handler);
		get_input(&input);
		if (ft_isemptystr(input, 1))
		{
			free(input);
		continue;
		}
		commands = ft_strsplit(input, ';');
		free(input);
		ret = exec_commands(commands);
		ft_freestrarr(commands);
		if (ret == -1)
			break;
	}
	ft_freestrarr(g_envv);
	return (0);
}

