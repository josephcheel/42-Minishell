#include "../../inc/minishell.h"

int	env_builtin(t_minishell *data)
{
	t_list *temp;

	temp = data->lstenv;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return 1;
}