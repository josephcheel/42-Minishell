#include "../../inc/minishell.h"

char **ft_separate_cmds(t_minishell *data)
{
	char **separate_cmds;

	separate_cmds = ft_split(data->raw_cmd, '|');
	return (separate_cmds);	
}

int	ft_multiple_commands(t_minishell *data)
{
	data->mul_cmds = ft_separate_cmds(data);
	return (0);
}

void	ft_init_data(t_minishell *data)
{
	data->nbr_of_cmds = ft_count_commands(data->raw_cmd);
	data->cmd = ft_split_quotes(data->raw_cmd);
	data->cmd_size= ft_cmdsize(data->cmd);
	data->cmd_and_arguments_size = ft_array_size(data->cmd);
}

int	ft_commands(t_minishell *data)
{
	if (ft_has_valid_quotes(data->raw_cmd) == 0)
		return (write(2, "quote>\n", 8));
	ft_init_data(data);
	// printf("%s", data->cmd[0]);
	if (data->nbr_of_cmds  == 1)
		ft_one_command(data);
	else
		ft_multiple_commands(data);
	return (0);
}

