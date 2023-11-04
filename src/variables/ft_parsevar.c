/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsevar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:36:04 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/03 01:52:36 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_get_export_id(char *variable)
{
	char	*final_result;
	char	*result;
	char	*non_alphanum;
	char	*size;

	if (variable[0] == '$')
		variable++;
	if (variable[0] == '?')
		return ("?");
	non_alphanum = ft_strdup(" !\"#$%%&\\\'()*+,-./:;<=>@[]^_`{|}~");
	size = ft_strpbrk(variable, non_alphanum);
	free(non_alphanum);
	result = ft_substr(variable, 0, size - variable);
	final_result = ft_strtrim(result, "\"|");
	free(result);
	return (final_result);
}

char	*ft_strchr_variable(char *raw_cmd)
{
	int		i;
	int		s_quote;
	char	*variable;

	i = 0;
	s_quote = 0;
	while (raw_cmd[i])
	{
		if (raw_cmd[i] == '\'')
			s_quote++;
		if ((raw_cmd[i] == '$' && ft_isalnum(raw_cmd[i + 1]) && s_quote == 0))
		{
			variable = ft_get_export_id(&raw_cmd[i + 1]);
			ft_check_var_rules(variable);
			free(variable);
			return (&raw_cmd[i]);
		}
		else if ((raw_cmd[i] == '$' && raw_cmd[i + 1] == '?') && s_quote == 0)
			return (&raw_cmd[i]);
		if (s_quote == 2)
			s_quote = 0;
		i++;
	}
	return (NULL);
}

char	*ft_status_variable(t_minishell *data, char *variable)
{
	char	*status;
	char	*result;

	status = ft_itoa(g_status.status);
	result = ft_replace_string(data->raw_cmd, variable, status);
	free(status);
	free(data->raw_cmd);
	return (result);
}

char	*ft_parse_variables(t_minishell *data)
{
	char	*result;
	char	*variable;
	t_env	*tmp;

	variable = ft_strchr_variable(data->raw_cmd);
	if (variable && ft_strlen(variable) > 1)
	{
		variable = ft_get_export_id(variable);
		if (ft_strcmp(variable, "?") == 0)
			return (ft_status_variable(data, variable));
		else
		{
			if (ft_isvariable(data->lstenv, variable))
			{
				tmp = ft_find_id(data->lstenv, variable);
				result = ft_replace_string(data->raw_cmd, tmp->id, tmp->value);
			}
			else
				result = ft_replace_string(data->raw_cmd, variable, "");
			free(variable);
			free(data->raw_cmd);
			return (result);
		}
	}
	return (data->raw_cmd);
}
