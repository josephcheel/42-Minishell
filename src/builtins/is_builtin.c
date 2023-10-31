/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:07:54 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/31 14:48:45 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_echo_type(t_minishell *data, char **cmd)
{
	if (data->cmd_size == 1)
		return (ft_echo(cmd, 0));
	else if (data->cmd_size == 2 && ft_strcmp(cmd[1], "-n") == 0)
		return (ft_echo(cmd, 1));
	else
		return (0);
}

static int	ft_exit_type(char **cmd, int multiple_cmd)
{
	if (multiple_cmd)
		return (ft_exit(cmd, 1));
	return (ft_exit(cmd, 0));
}

int	is_builtin(t_minishell *data, char **cmd, int multiple_cmd)
{
	int i;
	char *decapitalize;
	i = 0;

	decapitalize = ft_strlwr(cmd[0]);
	if (!ft_isstralnum(cmd[0]))
		return (0);
	// data->cmd_size = ft_cmdsize(cmd);
	if (ft_strncmp(decapitalize, "echo", 5) == 0)
		 i = ft_echo_type(data, cmd);
	else if (ft_strncmp(cmd[0], "cd", 3) == 0 && ft_array_size(cmd) >= 1)
		 i = ft_cd(data, cmd);
	else if (ft_strncmp(decapitalize, "pwd", 4) == 0)
		 i = ft_pwd(cmd);
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
		 i = ft_export(data, cmd);
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
		 i = ft_unset(data, cmd);
	else if (ft_strncmp(decapitalize, "env", 4) == 0)
		 i = ft_env(data->lstenv);
	else if (ft_strncmp(cmd[0], "exit", 5) == 0 && data->cmd_size >= 1)
		 i = ft_exit_type(cmd, multiple_cmd);
	free(decapitalize);
	return (i);
}
