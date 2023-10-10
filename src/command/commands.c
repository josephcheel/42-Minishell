#include "../../inc/minishell.h"

void	ft_init_data_one_cmd(t_minishell *data)
{
	data->cmd = ft_split_quotes(data->raw_cmd);
	data->cmd_size= ft_cmdsize(data->cmd);
	data->cmd_and_arguments_size = ft_array_size(data->cmd);
}

int	ft_commands(t_minishell *data)
{
	if (ft_has_valid_quotes(data->raw_cmd) == 0)
		return (write(2, "quote>\n", 8));
	// ft_init_data(data);
	data->nbr_of_cmds = ft_count_commands(data->raw_cmd);
	// printf("$%s$", data->cmd[1]);
	// return (0);
	ft_parse_variables(data);
	if (data->nbr_of_cmds  == 1)
	{
		ft_init_data_one_cmd(data);
		ft_one_command(data);
	}
	else
		ft_multiple_commands(data);
	return (0);
}

