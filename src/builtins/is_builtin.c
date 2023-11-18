/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:07:54 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/18 12:28:39 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_echo_type(char **cmd)
{
	int	cmd_size;

	cmd_size = ft_cmdsize(cmd);
	if (cmd_size == 1)
		return (ft_echo(cmd, 0));
	else if (cmd_size == 2 && ft_strcmp(cmd[1], "-n") == 0)
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

int	is_builtin(char **cmd)
{
	int		i;
	char	*decapitalize;

	i = 0;
	decapitalize = ft_strlwr(cmd[0]);
	if (!decapitalize)
		return (0);
	if (!ft_isstralnum(cmd[0]))
		return (0);
	if (ft_strcmp(decapitalize, "echo") == 0)
		i = 1;
	else if (ft_strcmp(cmd[0], "cd") == 0)
		i = 2;
	else if (ft_strcmp(decapitalize, "pwd") == 0)
		i = 3;
	else if (ft_strcmp(cmd[0], "export") == 0)
		i = 4;
	else if (ft_strcmp(cmd[0], "unset") == 0)
		i = 5;
	else if (ft_strcmp(decapitalize, "env") == 0)
		i = 6;
	else if (ft_strcmp(cmd[0], "exit") == 0)
		i = 7;
	free(decapitalize);
	return (i);
}

int	exec_builtin(t_minishell *data, char **cmd, int multiple_cmd, int cmd_nbr)
{
	int		i;

	i = 0;

	if (cmd_nbr == 1)
		i = ft_echo_type(cmd);
	else if (cmd_nbr == 2)
		i = ft_cd(data, cmd);
	else if (cmd_nbr == 3)
		i = ft_pwd(cmd);
	else if (cmd_nbr == 4)
		i = ft_export(data, cmd);
	else if (cmd_nbr == 5)
		i = ft_unset(data, cmd);
	else if (cmd_nbr == 6)
		i = ft_env(data->lstenv);
	else if (cmd_nbr == 7)
		i = ft_exit_type(cmd, multiple_cmd);
	return (i);
}
