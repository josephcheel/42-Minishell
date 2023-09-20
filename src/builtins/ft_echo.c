#include "../../inc/minishell.h"

int echo_builtin(t_minishell *data, int n_option)
{	
	int i;
	int count;

	if (data->cmd[1])
	{
		count = ft_array_size(data->cmd);
		i = ft_cmdsize(data->cmd) - 1;
		while (++i < count)
		{
			if (ft_strchr(data->cmd[i],'$'))
				printf("[%s] string has \"$\"\n", data->cmd[i]);
			printf("%s ", data->cmd[i]);
		}
	}
	if (n_option == 0)
		printf("\n");
	return (1);
}