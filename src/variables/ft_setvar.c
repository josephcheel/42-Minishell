#include "../../inc/minishell.h"

// Adds the variable if it does not exist in the env, otherwise changes the value of the node
void ft_set_variable(t_env **head, char *id, char *value)
{
	t_env *temp;

	if (ft_isvariable(*head, id))
	{
		temp = ft_find_id(*head, id);
		temp->value = value;
	}
	else
		ft_add_variable(head, id, value);
}