#include "../../inc/minishell.h"

int ft_echo(t_minishell *data, char **cmd, int n_option)
{	
	int i;
	int count;

	if (cmd[1])
	{
		count = ft_array_size(cmd);
		i = ft_cmdsize(cmd) - 1;
		while (++i < count - 1)
		{
			if (ft_strcmp(cmd[i], "$?") == 0)
			{
				printf("HOLA");
				printf("%d ", data->status);
				i++;
			}
			else
			{
				printf("%s", cmd[i]);
				printf(" ");
			}
		}
		if (ft_strcmp(cmd[i], "$?") == 0)
		{
			printf("%d", data->status);
			i++;
		}
		if (cmd[i])
			printf("%s", cmd[i]);
	}
	if (n_option == 0)
		printf("\n");
	return (1);
}