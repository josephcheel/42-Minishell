
#include "../../inc/environment.h"

char **ft_env_to_array(t_env *head)
{
	int i;
	int strsize;
	int lstsize;	
	t_env *temp;
	char **array;

	lstsize = ft_listsize(head);
	array = malloc(sizeof(char *) * lstsize + 1);

	i = 0;
	temp = head;
	while (i < lstsize)
	{
		strsize = ft_strlen(temp->id) + 1 + ft_strlen(temp->value);
		array[i] = malloc(sizeof(char) * strsize + 1);	
		ft_strlcpy(array[i], temp->id, strsize + 1);
		ft_strlcat(array[i], "=", strsize + 1);
		ft_strlcat(array[i], temp->value, strsize + 1);
		temp = temp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}