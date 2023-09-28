#include "../../inc/minishell.h"

char	*ft_return_argument(t_minishell *data)
{
	int		count;
	char	*new_str;

	count = data->cmd_size;
	// printf("COUNT %d\n", count);
	while (++count < data->cmd_and_arguments_size - 1)
	{
		new_str = ft_strjoinfree(new_str, data->cmd[count]);
		new_str = ft_strjoinfree(new_str, " ");
	}
	return (new_str);
}

int	ft_count_commands(char *raw_command)
{
	int	i;
	int	nbr_cmd;
	int	len_command;

	i = -1;
	nbr_cmd = 1;
	len_command = ft_strlen(raw_command);
	while (++i < len_command)
		if (raw_command[i] == '|')
			nbr_cmd++;
	return (nbr_cmd);
}

int ft_cmdsize(char **command) // counts the index from cmd and flags
{
	int	size;
	int	count;

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

int	commandline(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	if (!str1[i])
		return (1);
	else
		return (0);
}

char	**command_add(char **route, char *command)
{
	char	*copy;
	int		i;

	i = 0;
	copy = ft_strdup("/");
	if (!copy)
		return NULL;
		// function_errors();
	copy = ft_strjoinfree(copy, command);
	if (!copy)
		return NULL;
		// function_errors();
	while (route[i])
	{
		route[i] = ft_strjoinfree(route[i], copy);
		if (!route[i])
			return NULL;
			//function_errors();
		i++;
	}
	route[i] = NULL;
	free(copy);
	return (route);
}

char	*find_command_route_env(char **env, char *command)
{
	char	**route;
	char	*line;
	char	**temp;
	int		i;

	if (ft_strnstr(command, ".sh", ft_strlen(command))
		&& !ft_strchr(command, '/'))
		return (NULL);
	if (ft_strnstr(command, ".sh", ft_strlen(command)))
		return (command);
	while (!commandline("PATH", *env))
		env++;
	line = *env;
	while (*line != '/')
		line++;
	route = ft_split(line, ':');
	temp = ft_split(command, ' ');
	route = command_add(route, temp[0]);
	i = 0;
	while (route[i] && access(route[i], F_OK) == -1) //access?
		i++;
	if (!route[i])
		return (command);
	return (route[i]);
//Don't understand this part
}
//PATH