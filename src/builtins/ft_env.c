#include "../../inc/minishell.h"

int	env_builtin(t_minishell *data)
{
	t_env *temp;

	temp = data->lstenv;
	while (temp)
	{
		printf("%s", temp->id);
		printf("=");
		printf("%s\n", temp->value);
		temp = temp->next;
	}
	return 1;
}