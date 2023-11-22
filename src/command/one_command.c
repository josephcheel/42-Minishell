/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:48:33 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/18 19:49:42 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_builtin(t_minishell *data)
{
	int	builtin;

	builtin = is_builtin(data->cmd);
	if (builtin)
	{
		if (ft_redirect(data))
			return (1);
		exec_builtin(data, data->cmd, 0, builtin);
		return (1);
	}
	return (0);
}

int	ft_one_command(t_minishell *data)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	if (ft_builtin(data))
		return (0);
	else
	{
		data->pid = fork();
		if (data->pid == -1)
			return (1);
		else if (data->pid == 0)
			exec_one(data);
		waitpid(data->pid, &status, 0);
		if (WIFSIGNALED(status))
			catch_signal(data, status + 128, 1);
		else if (WIFEXITED(status))
			data->status = WEXITSTATUS(status);
	}
	return (0);
}
