#include "../../inc/minishell.h"

int	ft_isvariable(t_minishell *data, char *argument)
{
	t_list	*temp;

	temp = data->lstenv;
	while (temp)
	{
		if (ft_strncmp(temp->name, argument, ft_strlen(argument)) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}