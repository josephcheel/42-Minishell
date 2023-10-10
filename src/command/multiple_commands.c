#include "../../inc/minishell.h"

char **ft_separate_cmds(t_minishell *data)
{
	char **separate_cmds;

	separate_cmds = ft_split(data->raw_cmd, '|');
	return (separate_cmds);	
}

void	init_pipes(int **pipefd, int nbr_cmds)
{
	int i;

	i = 0;
	while (i < nbr_cmds)
	{
		pipe(pipefd[i]);
		i++;
	}
}

void	child_process(t_minishell *data, int nbr)
{
	pid_t pid;
	int fd[2];
	char * path;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		path = find_command_route_env(data->env, data->mul_cmds[nbr]);
		execve(path, ft_split_quotes(data->mul_cmds[nbr]), NULL);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd((ft_split_quotes(data->mul_cmds[nbr]))[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit (127);
		// exit(0);
	}
	else if (pid > 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
	waitpid(pid, NULL, 0);
}

int	ft_multiple_commands(t_minishell *data)
{
	int count;
	pid_t pid;

	count = -1;
	data->mul_cmds = ft_separate_cmds(data);

	pid = fork();
	if (pid == 0)
	{
		while (++count < data->nbr_of_cmds - 1)
			child_process(data, count);
		execve(find_command_route_env(data->env, data->mul_cmds[data->nbr_of_cmds - 1]), ft_split_quotes(data->mul_cmds[data->nbr_of_cmds - 1]), NULL);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(ft_split_quotes(data->mul_cmds[data->nbr_of_cmds - 1])[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit (127);
	}
	waitpid(pid, NULL, 0);
	

	return (0);
}