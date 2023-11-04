#include "../../inc/minishell.h"

char	**ft_separate_cmds(t_minishell *data)
{
	int		i;
	int		len;
	char	**separate_cmds;

	i = -1;
	separate_cmds = ft_split(data->raw_cmd, '|');
	len = ft_array_size(separate_cmds);
	while (separate_cmds[++i])
	{
		if (ft_isstralnum(separate_cmds[i]) == 0 && separate_cmds[len - 1] == separate_cmds[i])
		{
			ft_putstr_fd("pipe>\n", 2);
			return (NULL);
		}
		else if (ft_isstralnum(separate_cmds[i]) == 0)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
			return (NULL);
		}
	}
	// printf("SIZE: OF: %d\n", ft_array_size(separate_cmds));
	// // printf("CMD NOT EXIST: %s$\n", separate_cmds[1]);
	return (separate_cmds);	
}

// void	init_pipes(int **pipefd, int nbr_cmds)
// {
// 	int i;

// 	i = 0;
// 	while (i < nbr_cmds)
// 	{
// 		pipe(pipefd[i]);
// 		i++;
// 	}
// }

void	child_process(t_minishell *data, int nbr, int *fd)
{
	// pid_t pid;
	
	// char * path;

	
	// pid = fork();
	// if (pid == 0)
	// {
	if (data->nbr_of_cmds != nbr + 1)
		dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	// }
	// else if (pid > 0)
	// {
	// 	if (nbr < data->nbr_of_cmds - 1)
	// 	{
	// 		close(fd[1]);
	// 		dup2(fd[0], 0);
	// 		close(fd[0]);
	// 	}
	// }
	// waitpid(pid, NULL, 0); 
}

void	parent_process(int *fd)
{
	int i;

	i = 0;
	if (dup2(fd[0], 0) == -1 )
		i = 1;
	if (close(fd[0]) == -1 ) 
		i = 1;
	if (close(fd[1]) == -1 )
		i = 1;
	if (i == 1)
		exit(0);
}

int type_of_cmd(t_minishell *data, char *raw_cmd)
{
	char **cmd;

	cmd = ft_split_quotes(raw_cmd);
	if (is_builtin(data, cmd))
		printf("ONE_COMMAND\n");
	return (0);
}

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

int	ft_multiple_commands(t_minishell *data)
{
	int count;
	pid_t pid;
	int fd[2];

	count = -1;
	if (ft_check_pipe_sytax(data))
		return (0);
	data->mul_cmds = ft_separate_cmds(data);
	if (data->mul_cmds == NULL)
		return (0);

	while (++count < data->nbr_of_cmds )
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)	
		{
			child_process(data, count, fd);
			exec_multiple(data, data->mul_cmds[count]);
		}
		parent_process(fd);
		// waitpid(-1, NULL, 0);
	}
	// count = -1;
	int j;
	// // count -= 1;
	while (count--)
	{
		waitpid(-1, &j, 0);
		if (count == 0 && WIFSIGNALED(j))
		{
			if (j == 130)
				ft_putendl_fd("^C", STDOUT_FILENO);
			if (j == 131)
				ft_putstr_fd("^\\", STDOUT_FILENO);
		}
	}
	// 	else if
		
	// }
	
	// if (pid == 0)
	// printf("NBR CMD %d\n", data->nbr_of_cmds);
	// while (++count < data->nbr_of_cmds - 1)
	// type_of_cmd(data, data->mul_cmds[count]);
		
		// execve(find_command_route_env(data->env, data->mul_cmds[data->nbr_of_cmds - 1]), ft_split_quotes(data->mul_cmds[data->nbr_of_cmds - 1]), data->env);
		// ft_putstr_fd("minishell: ", 2);
		// ft_putstr_fd(ft_split_quotes(data->mul_cmds[data->nbr_of_cmds - 1])[0], 2);
		// ft_putstr_fd(": command not found\n", 2);
		// exit (127);
	

	return (0);
}