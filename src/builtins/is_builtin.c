/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:07:54 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/19 18:23:38 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_builtin(t_minishell *data, char **cmd)
{
	data->cmd_size = ft_cmdsize(cmd);
	if (ft_strncmp(ft_strlwr(cmd[0]), "echo", 5) == 0)
	{
		if (data->cmd_size == 1)
			return (ft_echo(cmd, 0));
		else if (data->cmd_size == 2 && ft_strncmp(cmd[1], "-n", 3) == 0)
			return (ft_echo(cmd, 1));
		else
			return (0);
	}
	else if (ft_strncmp(cmd[0], "cd", 3) == 0 && ft_array_size(cmd) >= 1)
		return (ft_cd(data, cmd));
	else if (ft_strncmp(ft_strlwr(cmd[0]), "pwd", 4) == 0)
		return (ft_pwd(cmd));
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
		return (ft_export(data, cmd));
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
		return (ft_unset(data, cmd));
	else if (ft_strncmp(ft_strlwr(cmd[0]), "env", 4) == 0)
		return (ft_env(data->lstenv));
	else if (ft_strncmp(cmd[0], "exit", 5) == 0 && data->cmd_size >= 1)
		return (exit_builtin(data));
	return (0);
}
