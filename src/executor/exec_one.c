/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:55:10 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/18 20:55:10 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_one(t_minishell *data)
{
	char	*path;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	if (!ft_isstrprint(data->cmd[0]))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(data->cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit (127);
	}
	path = find_command_route_env(data->lstenv, data->cmd[0]);
	if (!path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(data->cmd[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(1);
	}
	if (ft_redirect(data))
		exit(1);
	execve(path, data->cmd, data->env);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(data->cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free(path);
	ft_array_free(data->cmd, ft_array_size(data->cmd));
	exit (127);
}
