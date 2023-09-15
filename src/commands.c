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
	count = ft_arraysize(command);
	while (size < count)
	{
		if (ft_strncmp(command[size], "-", 1) <= 0)
			size++;
		else
			break;
	}
	return (size);
}

int is_builtin(char *cmd)
{
	// char *cmd_lowercase;
	// printf("%s\n", cmd);
	// cmd_lowercase= uncapitalize(cmd);
	
	if (ft_strncmp(cmd, "echo", 4) == 0) // ignores case
		return (1);
	else if (ft_strncmp(cmd, "cd", 4) == 0) // only lower caser
		return (1);
	else if (ft_strncmp(cmd, "pwd", 4) == 0) //  ignores case
		return (1);
	else if (ft_strncmp(cmd, "export", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd, "unset", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd, "env", 4) == 0) //  ignores case
		return (1);
	else if (ft_strncmp(cmd, "exit", 4) == 0) // only lower caser
		return (1);
	return (0);
}

int ft_one_command(char *raw_command)
{
	char **command;

	if (ft_strlen(raw_command) == 0)
		return 0;
	command = ft_split_quotes(raw_command);
	int count = ft_arraysize(command);
	for (int i = 0; i < count; i++)
	{
		printf("command[%d]: $%s$\n", i, command[i]);
	}

	if (is_builtin(command[0]) == 1)
	{
		echo_builtin(command);
		printf("size of command: %d\n", ft_cmdsize(command));
	} 
	else
	{

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
	if (nbr_cmd == 1)
		ft_one_command(raw_command);
	(void)envv;
	return (0);
}