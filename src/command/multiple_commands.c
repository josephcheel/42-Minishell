#include "../../inc/minishell.h"

char	**ft_separate_cmds(t_minishell *data)
{
	int		i;
	int		len;
	char	**separate_cmds;

	i = -1;
	separate_cmds = ft_split_pipe(data->raw_cmd, '|');
	len = ft_array_size(separate_cmds);
	while (separate_cmds[++i])
	{
		if (ft_isstralnum(separate_cmds[i]) == 0 && \
			(separate_cmds[len - 1] == separate_cmds[i]))
		{
			ft_putstr_fd("pipe>\n", 2);
			ft_array_free(separate_cmds, len);
			return (NULL);
		}
		else if (ft_isstralnum(separate_cmds[i]) == 0 \
			|| (ft_isstralnum(separate_cmds[i]) == 0
			&& separate_cmds[0] == separate_cmds[i]))
		{
			ft_array_free(separate_cmds, len);
			ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
			return (NULL);
		}
	}
	return (separate_cmds);	
}

void	child_process(t_minishell *data, int nbr)
{
	if (nbr != data->nbr_of_cmds - 1)
		dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
	close(data->fd[0]);
}

// void	signal_handler_mul(int sig)
// {
// 	if (sig == SIGQUIT)
// 	{
// 		// rl_replace_line("", 0);
// 		// ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
// 		rl_on_new_line();
// 		rl_redisplay();
// 	}
// }

int ft_check_pipe_sytax(t_minishell *data)
{
	if (data->raw_cmd[0] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	if (data->raw_cmd[ft_strlen(data->raw_cmd) - 1] == '|')
	{
		ft_putstr_fd("pipe>\n", 2);
		return (1);
	}
	return (0);
}

static void	parent(t_minishell *master)
{
	int	i;

	i = 0;
	if (dup2(master->fd[0], STDIN_FILENO) == -1)
		i = 1;
	if (close(master->fd[0]) == -1)
		i = 1;
	if (close(master->fd[1]) == -1)
		i = 1;
	(void)i;
	// if (i)
	// 	clean_free(master, 1);
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
		// if (pid == -1)
		// 	clean_free(master, 1);
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
	int nbr;
	
	nbr = -1;
	// if (ft_check_pipe_sytax(data))
	// 	return (0);
	data->mul_cmds = ft_separate_cmds(data);
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
		if (data->pid  == 0)
		{
			signal(SIGINT, signal_handler);
			signal(SIGQUIT, signal_handler);
			child_process(data, nbr);
			exec_multiple(data, data->mul_cmds[nbr]);
		}
		parent(data);
	}
	ft_array_free(data->mul_cmds, ft_array_size(data->mul_cmds));
	wait_childs(data);
	return (0);
}