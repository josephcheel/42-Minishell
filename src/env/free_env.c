#include "../../inc/environment.h"

void	ft_free_env(t_env *head)
{
	t_env	*temporary;

	temporary = head;
	while (temporary != NULL)
	{
		
		free(temporary->id);
		free(temporary->value);
		temporary = temporary->next;
	}
}