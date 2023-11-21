/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:24:10 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/18 21:05:45 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	parent(t_minishell *data)
{
	dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[0]);
	close(data->fd[1]);
}

void	child_process(t_minishell *data, int nbr)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	if (nbr != data->nbr_of_cmds - 1)
		dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
	close(data->fd[0]);
}

static void	wait_childs(t_minishell *data)
{
	int	nbr;
	int	pid;
	int	status;

	nbr = data->nbr_of_cmds;
	if (nbr == 1)
		return ;
	while (nbr--)
	{
		pid = waitpid(-1, &status, 0);
		if (nbr == 0 && WIFSIGNALED(status))
		{
			status += 128;
			catch_signal(data, status, 0);
		}
		else if (pid == data->pid)
			if (WIFEXITED(status))
				data->status = WEXITSTATUS(status);
	}
}

int	ft_multiple_commands(t_minishell *data)
{
	int	nbr;

	nbr = -1;
	if (data->mul_cmds == NULL)
		return (0);
	while (++nbr < data->nbr_of_cmds)
	{
		pipe(data->fd);
		signal(SIGINT, SIG_IGN);
		data->pid = fork();
		if (data->pid < 0)
		{
			close(data->fd[1]);
			close(data->fd[0]);
			exit (0);
		}
		if (data->pid == 0)
		{
			child_process(data, nbr);
			exec_multiple(data, data->mul_cmds[nbr]);
		}
		parent(data);
	}
	wait_childs(data);
	return (0);
}
