#include "../inc/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_minishell	data;

	if (ac != 1 && !av)
		return (1);
	init_env(&data, env);
	while (1)
	{
		signal(SIGINT, signal_handler);
		data.raw_cmd = display_prompt_msg();
		data.last_return_nbr = 0;

		if (ft_strlen(data.raw_cmd) > 0)
			ft_commands(&data);
		//ft_freemini(commands);
	}
	//ft_freemini(env);
	return (0);
}

