#include "../../inc/minishell.h"

int ft_echo(char **cmd, int n_option)
{	
	int i;
	int count;

	if (cmd[1])
	{
		count = ft_array_size(cmd);
		i = ft_cmdsize(cmd) - 1;
		while (++i < count - 1)
		{
			printf("%s", cmd[i]);
			printf(" ");
		}
		if (cmd[i])
			printf("%s", cmd[i]);
	}
	if (n_option == 0)
		printf("\n");
	return (1);
}