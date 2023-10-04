#include "../../inc/minishell.h"

int	init_env(t_minishell *data, char **env)
{
	int		i;
	int		count;
	char	**split;
	t_env	*temp;
	
	i = 0;
	count = ft_array_size(env);
	data->lstenv = NULL;
	data->env = env;
	while (i < count)
	{
		split = ft_split_env(env[i]); // split name and value divided by '='		
		temp = ft_create_new_node(split[0], split[1]);
		ft_insert_at_end(&data->lstenv, temp);
		i++;
	}
	return 0;
}

// //sorting the environment variables
// //pointers creation per each variable