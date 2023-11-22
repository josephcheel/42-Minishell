/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:31:49 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 21:37:45 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_count_commands(char *raw_command)
{
	int		i;
	int		nbr_cmd;
	int		len_command;
	t_quote	quotes;

	i = -1;
	quotes.simple = 0;
	quotes.dbl = 0;
	nbr_cmd = 1;
	len_command = ft_strlen(raw_command);
	while (++i < len_command)
	{
		if (raw_command[i] == '\"' || raw_command[i] == '\'')
			ft_get_quotes_values(raw_command[i], &quotes);
		if (raw_command[i] == '|' && quotes.dbl == 0 && quotes.simple == 0)
		{
			ft_write_syntax_error(raw_command, i);
			nbr_cmd++;
		}
	}
	return (nbr_cmd);
}

/*
** counts the index from cmd and flags
*/
int	ft_cmdsize(char **command)
{
	int	size;
	int	count;

	size = 0;
	if (ft_strlen(command[0]) > 0)
		size++;
	else
		return (size);
	count = ft_array_size(command);
	while (size < count)
	{
		if (command[size][0] == '-')
			size++;
		else
			break ;
	}
	return (size);
}

int	commandline(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	if (!str1[i])
		return (1);
	else
		return (0);
}

char	**command_add(char **route, char *command)
{
	char	*copy;
	int		i;

	i = 0;
	copy = ft_strdup("/");
	if (!copy)
		return (NULL);
	copy = ft_strjoinfree(copy, command);
	if (!copy)
		return (NULL);
	while (route[i])
	{
		route[i] = ft_strjoinfree(route[i], copy);
		if (!route[i])
			return (NULL);
		i++;
	}
	route[i] = NULL;
	free(copy);
	return (route);
}

char	*find_command_route_env(t_env *lstenv, char *command)
{
	char	**route;
	char	*line;
	char	*str;
	int		i;

	line = NULL;
	i = 0;
	line = ft_first_step(lstenv, command, line);
	if (!line)
		return (NULL);
	route = ft_split(line, ':');
	route = command_add(route, command);
	while (route[i] && access(route[i], F_OK) == -1)
		i++;
	if (!route[i])
	{
		str = ft_strtrim(command, " ");
		ft_array_free(route, ft_array_size(route));
		return (str);
	}
	str = ft_strdup(route[i]);
	ft_array_free(route, ft_array_size(route));
	return (str);
}
