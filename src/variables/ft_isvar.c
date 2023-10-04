#include "../../inc/minishell.h"

// Check if a variable name(id) is on the env list 
int	ft_isvariable(t_env *head, char *id)
{
	t_env	*temp;

	temp = head;
	while (temp)
	{
		if (ft_strncmp(temp->id, id, ft_strlen(id)) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}