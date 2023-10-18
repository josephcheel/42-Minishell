 #include "../../inc/minishell.h"

// int ft_nbr_of_appeareance(char *str, int c)
// {
// 	int i;
// 	int count;

// 	i = -1;
// 	count = 0;
// 	while (str[++i])
// 	{
// 		if (str[i] == c)
// 			count++;
// 	}
// 	return (count);
// }

// int	ft_check_export_syntax(char *str) //true == okey ; false == not okey
// {
// 	if (str[0] == '$')
// 	{	
// 		str++;
// 		return (0);
// 	}
// 	if (ft_array_size(ft_split(str, '=')) == 2)
// 		return (1);
// 	else
// 		return (0);
// }

// int	ft_is_variable_export(t_minishell *data, char *argument)
// {
// 	char	**variable;
// 	t_list	*temp;

// 	variable = ft_split_env(argument);
// 	temp = data->lstenv;
// 	while (temp)
// 	{
// 		if (ft_strncmp(temp->name, variable[0], ft_strlen(variable[0])) == 0)
// 		{
// 			temp->content = argument;
// 			temp->value = variable[1];
// 			return (1);
// 		}
// 		temp = temp->next;
// 	}
// 	return (0);
// }

int ft_check_var_rules(char *var)
{
	int i;

	i = 0;
	if (ft_isdigit(var[i]))
		return (0);
	while (var[i])
	{
		if (ft_isalnum(var[i]) == 0 || var[i] != '_')
			return (0);
		i++;	
	}
	return (1);
}

int	export_builtin(t_minishell *data) //TODO: remove quote and spaces
{
	(void)data;
// 	int size;
// 	int start;
// 	char **split;
// 	t_list *temp;
	
// 	start = data->cmd_size;
// 	size =  data->cmd_and_arguments_size;
// 	while (start < size)
// 	{
// 		if (ft_check_export_syntax(data->cmd[start]) && ft_is_variable_export(data, data->cmd[start]) == 0)
// 		{
// 			split = ft_split_env(data->cmd[start]);
// 			temp = ft_lstnew(data->cmd[start]);
// 			temp->name = split[0];
// 			temp->value = split[1];
// 			ft_lstadd_back(&data->lstenv, temp);
// 		}
// 		start++;
// 	}
	// t_env *temp;
	

	// while ()
	// {
	// 	if (ft_check_var_rules());
	// 	{
	// 		ft_split_env()
	// 		ft_
	// 		temp =ft_create_new_node();
	// 		ft_insert_at_end(data->lstenv, temp);
	// 	}
	// }
	
	// data->cmd[1]
	data->env = ft_env_to_array(data->lstenv);
 	return (1);	
}
