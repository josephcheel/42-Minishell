#include "../../inc/minishell.h"

char **ft_separate_cmds(t_minishell *data)
{
	int i;
	int len;
	char **separate_cmds;
	

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

void	child_process(t_minishell *data, int nbr)
{

	// if (data->pid  == 0)
	// {
		if (nbr != data->nbr_of_cmds - 1)
			dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[1]);
		close(data->fd[0]);
		
		// exec_multiple(data, data->mul_cmds[nbr]);

	// }
	// else if (data->pid  > 0)
	// {
	// 	close(data->fd[1]);
	// 	dup2(data->fd[0], 0);
	// 	close(data->fd[0]);
	// }
	// waitpid(data->pid , NULL, 0); 
}

// int type_of_cmd(t_minishell *data, char *raw_cmd)
// {
// 	char **cmd;

// 	cmd = ft_split_quotes(raw_cmd);
// 	if (is_builtin(data, cmd))
// 		printf("ONE_COMMAND\n");
// 	return (0);
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
static void	aux_wait_childs(int code)
{
	if (code == 130)
		ft_putendl_fd("^C", STDOUT_FILENO);
	if (code == 131)
		ft_putstr_fd("^\\", STDOUT_FILENO);
}

static void	wait_childs(t_minishell *data)
{
	int	i;
	int	pid;
	int	j;

	i = data->nbr_of_cmds;
	// init_signal(1);
	if (i == 1)
		return ;
	while (i--)
	{
		j = 0;
		pid = waitpid(-1, &j, 0);
		// if (pid == -1)
		// 	clean_free(master, 1);
		if (i == 0 && WIFSIGNALED(j))
		{
			j += 128;
			aux_wait_childs(j);
		}
		else if (pid == data->pid)
			if (WIFEXITED(j))
				data->status = WEXITSTATUS(j);
	}
}

int	ft_multiple_commands(t_minishell *data)
{
	int nbr;
	

	nbr = -1;
	if (ft_check_pipe_sytax(data))
		return (0);
	data->mul_cmds = ft_separate_cmds(data);
	if (data->mul_cmds == NULL)
		return (0);
	
	while (++nbr < data->nbr_of_cmds)
	{
		pipe(data->fd);
		data->pid = fork();
		// signal(SIGINT, SIG_IGN);
		if (data->pid < 0)
		{
			close(data->fd[1]);
			close(data->fd[0]);
			exit (0);
		}
		if (data->pid  == 0)
		{
			child_process(data, nbr);
			exec_multiple(data, data->mul_cmds[nbr]);
		}
		parent(data);
	}
	wait_childs(data);
	return (0);
}