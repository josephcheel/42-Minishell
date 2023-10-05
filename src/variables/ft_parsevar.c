#include "../../inc/minishell.h"

char *ft_get_variable(char *variable)
{
	char **split;

	if (variable[0] == '$')
		variable++;
	split = ft_split(variable, ' ');
	return (split[0]);
}

char *ft_parse_variables(t_minishell *data)
{
	char *variable;
	t_env *temp;

	variable = ft_strchr(data->raw_cmd, '$');
	if (variable)
	{
		variable = ft_get_variable(variable);
		if (ft_isvariable(data->lstenv, variable))
		{
			temp = ft_find_id(data->lstenv, variable);
			printf("replaced string %s\n", ft_replace_string(data->raw_cmd, temp->id, temp->value));			
		}
	}
	return (NULL);
}
