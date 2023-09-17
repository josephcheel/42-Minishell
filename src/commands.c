#include "../inc/minishell.h"

int ft_cmdsize(char **command) // counts the index from cmd and flags
{
	int size;
	int count;

	size = 0;
	if (ft_strlen(command[0]) > 0)
		size++;
	else 
		return (size);
	count = ft_array_size(command);
	while (size < count)
	{
		if (ft_strncmp(command[size], "-", 1) <= 0)
			size++;
		else
			break;
	}
	return (size);
}

int is_builtin(char **cmd)
{
	int cmd_size;

	cmd_size = ft_cmdsize(cmd);
	if (ft_strncmp(ft_strlwr(cmd[0]), "echo", 5) == 0) // ignores case
	{
		if (cmd_size == 1)
			return (echo_builtin(cmd, 0));
		else if (cmd_size == 2 && ft_strncmp(cmd[1], "-n", 3) == 0)
			return (echo_builtin(cmd, 1));
		else
			return (0);
	}
	else if (ft_strncmp(cmd[0], "cd", 3) == 0 && ft_array_size(cmd) == 2) // only lower caser
		return (1);
	else if (ft_strncmp(ft_strlwr(cmd[0]), "pwd", 4) == 0 && cmd_size == 1) //  ignores case
		return (1);
	else if (ft_strncmp(cmd[0], "export", 7) == 0 && cmd_size == 1)
		return (1);
	else if (ft_strncmp(cmd[0], "unset", 6) == 0 && cmd_size == 1)
		return (1);
	else if (ft_strncmp(ft_strlwr(cmd[0]), "env", 4) == 0 && cmd_size == 1) //  ignores case
		return (1);
	else if (ft_strncmp(cmd[0], "exit", 5) == 0 && cmd_size >= 1) // only lower caser
		return (0);
	return (0);
}

int ft_one_command(char *raw_command, char **envv)
{
	char **command;

	if (ft_strlen(raw_command) == 0)
		return 0;
	if (ft_has_valid_quotes(raw_command) == 0)
		return (write(2, "quote>\n", 8));
	command = ft_split_quotes(raw_command);
	
	// DEBUGG CODE
	int count = ft_array_size(command);	
	for (int i = 0; i < count; i++)		
	{
		// printf("command[%d]: $%s$\n", i, command[i]);
	}
	// END DEBUG CODE

	if (is_builtin(command) == 1)
		return (0);
	else
	{
		execve(envvcommand[0],[]NULL);
	}
	return (0);
}

int	ft_count_commands(char *raw_command)
{
	int i;
	int nbr_cmd;
	int len_command;

	i = -1;
	nbr_cmd = 1;
	len_command = ft_strlen(raw_command);
	while (++i < len_command)
		if (raw_command[i] == '|')
			nbr_cmd++;
	return (nbr_cmd);
}

int	ft_commands(char *raw_command, char **envv)
{
	int nbr_cmd;
	
	nbr_cmd = ft_count_commands(raw_command);
	// printf("NBR CMD: %d\n", nbr_cmd);
	if (nbr_cmd == 1)
		ft_one_command(raw_command, envv);
	(void)envv;
	return (0);
}