#include "../../inc/minishell.h"

void	ft_init_data_one_cmd(t_minishell *data)
{
	data->cleaned_cmd = ft_clean_redir_cmd(data->raw_cmd);
	// printf("%p\n", data->cleaned_cmd);
	// printf("%p\n", data->raw_cmd);
	// printf("cleaned: %s\n raw %s", data->cleaned_cmd, data->raw_cmd);
	data->cmd = ft_split_quotes(data->cleaned_cmd);
	data->cmd_size = ft_cmdsize(data->cmd);
	data->cmd_and_arguments_size = ft_array_size(data->cmd);
}

static void	ft_free_one(t_minishell *data)
{
	if (data->raw_cmd)
		free(data->raw_cmd);
	if (data->cleaned_cmd)
		free(data->cleaned_cmd);
	if (data->cmd)
		ft_array_free(data->cmd, ft_array_size(data->cmd));
	if (data->infile)
		free(data->infile);
	if (data->outfile)
		free(data->outfile);
	if (data->heredoc)
		free(data->heredoc);
	data->infile = NULL;
	data->outfile = NULL;
	data->heredoc = NULL;
}

int	ft_commands(t_minishell *data)
{
	if (ft_has_valid_quotes(data->raw_cmd) == 0)
		return (write(2, "quote>\n", 8));
	
	data->nbr_of_cmds = ft_count_commands(data->raw_cmd);
	if (data->nbr_of_cmds == 0)
		return (0);
	
	while (ft_strchr_variable(data->raw_cmd))
		data->raw_cmd = ft_parse_variables(data);
	
	if (ft_isallspace(data->raw_cmd))
		return (0);
	
	if (data->nbr_of_cmds == 1)
	{
		ft_init_data_one_cmd(data);
		ft_one_command(data);
		ft_free_one(data);
	}
	else
	{
		ft_multiple_commands(data);
		free(data->raw_cmd);
	}
	return (0);
}
