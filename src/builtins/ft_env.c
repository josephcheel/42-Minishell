#include "../../inc/minishell.h"

int	ft_env(t_env *lstenv)
{
	t_env *temp;

	temp = lstenv;
	while (temp)
	{
		printf("%s", temp->id);
		printf("=");
		printf("%s\n", temp->value);
		temp = temp->next;
	}
	return (1);
}