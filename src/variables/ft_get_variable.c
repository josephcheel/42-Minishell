#include "../../inc/minishell.h"

char *ft_get_variable(t_env **head, char *id)
{
	t_env *temp;

	if (ft_isvariable(*head, id))
	{
		temp = ft_find_id(*head, id);
		return (temp->value);
	}
	else
		return (NULL);
}