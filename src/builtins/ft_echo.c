#include "../../inc/minishell.h"


// QUICK ECHO //
int echo_builtin(char **command)
{	
	int last_return_nbr = 0; // change
	
	if (command[1] && ft_strncmp(command[1], "$?", 2) == 0)
	{
		printf("%d", last_return_nbr);
	}
	else if (command[1])
	{
		int count;

		count = ft_arraysize(command);
		int i = 0;
		while (++i < count - 1)
			printf("%s ", command[i]);
		printf("%s", command[i]);
	}
	printf("\n");
	// control if string has $() with double quotes
	return (0);
}