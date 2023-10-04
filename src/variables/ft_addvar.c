#include "../../inc/minishell.h"

//Adds variable to list
void	ft_add_variable(t_env **head, char *id, char *value)
{
	t_env *temp;
	t_env *new_node;

	new_node = ft_create_new_node(id, value);
	if (!new_node)
		return ;
	temp = *head;
	if (!temp)
        *head = new_node;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}