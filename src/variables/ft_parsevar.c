#include "../../inc/minishell.h"

char *ft_get_export_id(char *variable)
{
	char **split;

	if (variable[0] == '$')
		variable++;
	split = ft_split(variable, ' ');
	// printf("split: %s\n", split[0]);
	return (ft_strtrim(split[0], "\""));
}

char *ft_parse_variables(t_minishell *data)
{
	char *result;
	char *variable;
	t_env *temp;


	variable = ft_strchr(data->raw_cmd, '$');
	if (variable && ft_strlen(variable) > 1)
	{
		variable = ft_get_export_id(variable);
		if (ft_strcmp(variable, "?") == 0)
		{
			result = ft_replace_string(data->raw_cmd, variable, ft_itoa(data->status));
			return (result);
		}
		else
		{
			if (ft_isvariable(data->lstenv, variable))
			{
				temp = ft_find_id(data->lstenv, variable);
				result = ft_replace_string(data->raw_cmd, temp->id, temp->value);
				return (result);		
			}
			else
			{	
				result = ft_replace_string(data->raw_cmd, variable, "");
				return (result);
			}
		}
	}
	return (data->raw_cmd);
}
