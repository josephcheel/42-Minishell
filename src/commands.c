#include "../inc/minishell.h"

char **ft_separate_cmds(t_minishell *data)
{
	char **separate_cmds;

	separate_cmds = ft_split(data->raw_cmd, '|');
	return (separate_cmds);	
}

int	ft_multiple_commands(t_minishell *data)
{
	// int count;

	// count = -1;
	data->mul_cmds = ft_separate_cmds(data);
	// while (++count < data->cmd_and_arguments_size -1 )
	// {
	// int count = ft_array_size(data->mul_cmds);	
	// for (int i = 0; i < count; i++)		
	// {
	// 	printf("command[%d]: $%s$\n", i, data->mul_cmds[i]);
	// }
	// 	printf("\n");
	// }	
	return (0);
}

int ft_one_command(t_minishell *data, char **envv)
{
	
	(void)envv;
	if (is_builtin(data) == 1)
		return (0);
	else
	{
		int pid = fork();
		if (pid == 0)
			execve(find_command_route_env(envv, data->raw_cmd), data->cmd,NULL);
			// execve(NULL, command,NULL);
		waitpid(pid, NULL, 0);
	}
	return (0);
}

int	ft_commands(t_minishell *data, char **envv)
{
	if (ft_has_valid_quotes(data->raw_cmd) == 0)
		return (write(2, "quote>\n", 8));
	data->nbr_of_cmds = ft_count_commands(data->raw_cmd);
	// printf("NBR CMD: %d\n", nbr_cmd);
	data->cmd = ft_split_quotes(data->raw_cmd);
	int count = ft_array_size(data->cmd);	
	for (int i = 0; i < count; i++)		
	{
		printf("command[%d]: $%s$\n", i, data->cmd[i]);
	}
	if (data->nbr_of_cmds  == 1)
		ft_one_command(data, envv);
	else
		// ft_multiple_commands(data);
	(void)envv;
	return (0);
}


/* TO DEBUG
// DEBUGG CODE
int count = ft_array_size(data->cmd);	
for (int i = 0; i < count; i++)		
{
	//printf("command[%d]: $%s$\n", i, command[i]);
}
// END DEBUG CODE */