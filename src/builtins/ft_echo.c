#include "../../inc/minishell.h"


// QUICK ECHO //
int echo_builtin(char **command, int n_option)
{	
	int last_return_nbr = 0; // change
	int i;
	int count;
	if (command[1] && ft_strncmp(command[1], "$?", 2) == 0)
		printf("%d", last_return_nbr);
	else if (command[1])
	{
		count = ft_array_size(command);
		i = ft_cmdsize(command) - 1;
		while (++i < count - 1)
			printf("%s ", command[i]);
		if (command[i])
			printf("%s", command[i]);
	}
	if (n_option == 0)
		printf("\n");
	// control if string has $() with double quotes
	return (0);
}