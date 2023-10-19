#include "../../inc/minishell.h"

// Check if a variable name(id) is on the env list 
int	ft_isvariable(t_env *head, char *id)
{
	t_env	*temp;

	temp = head;
	while (temp)
	{
		if (ft_strcmp(temp->id, id) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}