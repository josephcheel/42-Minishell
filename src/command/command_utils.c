#include "../../inc/minishell.h"

int	ft_count_commands(char *raw_command)
{
	int	i;
	int	nbr_cmd;
	int	len_command;
	int in_single;
	int in_double;
	i = -1;
	
	in_single = 0;
	in_double = 0;
	nbr_cmd = 1;
	len_command = ft_strlen(raw_command);
	while (++i < len_command)
	{
		if (raw_command[i] == '\"' || raw_command[i] == '\'')
		{
			if (raw_command[i] == '\"' && in_single == 0)
				in_double++;
			else if (raw_command[i] == '\'' && in_double == 0)
				in_single++;
			if (in_single == 2)
			{
				in_single = 0;
			}
			if	(in_double == 2)
			{
				in_double = 0;
			}
		}
		if (raw_command[i] == '|' && in_double == 0 && in_single == 0)
		{
			if (raw_command[i+1] == '|')
			{
				ft_putstr_fd("minishell: syntax error near unexpected token `|'\n",2);
				return (0);
			}
			nbr_cmd++;
		}
	}
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
		if (command[size][0] == '-')
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

char	*find_command_route_env(t_env *lstenv, char **env, char *command)
{
	char	**route;
	char	*line;
	char	**temp;
	char	*str;
	t_env	*envtemp;
	int		i;

	(void)env;
	if (!ft_isstralnum(command))
		return (NULL);
	if (ft_isvariable(lstenv, "PATH"))
	{
		envtemp = ft_find_id(lstenv, "PATH");//getenv("PATH");
		line = envtemp->value;
	}
	else
		return (NULL);
	while (*line != '/')
		line++;
	if (!line)
		return (NULL);
	route = ft_split(line, ':');
	temp = ft_split(command, ' ');
	route = command_add(route, temp[0]);
	ft_array_free(temp, ft_array_size(temp));
	i = 0;
	while (route[i] && access(route[i], F_OK) == -1) //access?
		i++;
	if (!route[i])
	{
		str = ft_strtrim(command, " ");
		ft_array_free(route, ft_array_size(route));
		return (str);	
	}
	str = ft_strdup(route[i]);
	ft_array_free(route, ft_array_size(route));
	return (str);
//Don't understand this part
}