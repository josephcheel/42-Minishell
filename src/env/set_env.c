#include "../../inc/minishell.h"

t_list	*ft_lstfind_name(t_list **lst, char *find)
{
	t_list	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->name, find, ft_strlen(find) + 1) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	init_env(t_minishell *data, char **env)
{
	int		i;
	int		count;
	char	**split;
	t_list	*temp; //libft.h
	
	i = 0;
	
	count = ft_array_size(env);
	data->lstenv = NULL;
	data->env = env;
	while (i < count)
	{
		temp = ft_lstnew(env[i]);
		split = ft_split_env(env[i]); // split name and value divided by '='		
		temp->name = split[0];
		temp->value = split[1];
		ft_lstadd_back(&data->lstenv, temp);
		i++;
	}
	return 0;
}

//sorting the environment variables
//pointers creation per each variable