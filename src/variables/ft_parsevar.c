/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsevar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:36:04 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 12:55:21 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_get_export_id(char *variable)
{
	char	**split;

	if (variable[0] == '$')
		variable++;
	split = ft_split(variable, ' ');
	return (ft_strtrim(split[0], "\""));
}

char	*ft_parse_variables(t_minishell *data)
{
	char	*result;
	char	*variable;
	t_env	*tmp;

	variable = ft_strchr(data->raw_cmd, '$');
	if (variable && ft_strlen(variable) > 1)
	{
		variable = ft_get_export_id(variable);
		if (ft_strcmp(variable, "?") == 0)
			return (ft_replace_string(data->raw_cmd, variable,
					ft_itoa(g_status.status)));
		else
		{
			if (ft_isvariable(data->lstenv, variable))
			{
				tmp = ft_find_id(data->lstenv, variable);
				result = ft_replace_string(data->raw_cmd, tmp->id, tmp->value);
			}
			else
				result = ft_replace_string(data->raw_cmd, variable, "");
			return (result);
		}
	}
	return (data->raw_cmd);
}
