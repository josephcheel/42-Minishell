#include "../../inc/environment.h"

void	ft_free_env(t_env *head)
{
	t_env	*temporary;

	temporary = head;
	while (temporary != NULL)
	{
		if (temporary->id)
			free(temporary->id);
		if (temporary->value)
			free(temporary->value);
		temporary = temporary->next;
	}
}
