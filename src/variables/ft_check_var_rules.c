#include "../../inc/minishell.h"

int ft_check_var_rules(char *var)
{
	int i;

	i = 0;
	if (ft_isdigit(var[i]))
		return (0);
	while (var[i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (0);
		i++;	
	}
	return (1);
}