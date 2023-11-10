#include "../../inc/minishell.h"

void	ft_init_data_one_cmd(t_minishell *data)
{
	data->cleaned_cmd = ft_clean_redir_cmd(data->raw_cmd);
	
	data->cmd = ft_split_quotes(data->cleaned_cmd);
	data->cmd_size = ft_cmdsize(data->cmd);
	data->cmd_and_arguments_size = ft_array_size(data->cmd);
	// data->in_files = malloc(sizeof(t_list));
	// data->out_files = malloc(sizeof(t_list));
	// data->out_append = malloc(sizeof(t_list));
	data->in_files = NULL;
	data->out_files = NULL;
	data->out_append = NULL;
	data->heredocs = NULL;
	data->is_append = 0;
	data->is_heredoc = 0;
	ft_get_redit_value(data->raw_cmd, data);
}

void ft_free_list(t_list **head)
{
	t_list *temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp->content);
		free(temp);
	}
}

static void	ft_free_one(t_minishell *data)
{
	if (data->raw_cmd)
		free(data->raw_cmd);
	if (data->cleaned_cmd)
		free(data->cleaned_cmd);
	if (data->cmd)
		ft_array_free(data->cmd, ft_array_size(data->cmd));
	if (ft_lstsize(data->in_files) > 0)
		ft_free_list(&data->in_files);
	if (ft_lstsize(data->out_files) > 0)
		ft_free_list(&data->out_files);
	if (ft_lstsize(data->out_append) > 0)
		ft_free_list(&data->out_append);
	if (ft_lstsize(data->heredocs) > 0)
		ft_free_list(&data->heredocs);
	// printf("free\n"); //
}


static int ft_syntax_errors(t_minishell *data)
{
	if (ft_has_valid_quotes(data->raw_cmd) == 0)
	{
		free(data->raw_cmd);
		return (write(2, "quote>\n", 8));
	}
	if (ft_check_pipe_sytax(data))
	{
		free(data->raw_cmd);
		return (1);
	}
	if (ft_check_redir_sytax(data->raw_cmd))
	{
		free(data->raw_cmd);
		return (1);
	}
	return (0);
}

int	ft_commands(t_minishell *data)
{
	
	if (ft_syntax_errors(data))
		return (0);
	data->nbr_of_cmds = ft_count_commands(data->raw_cmd);
	

	while (ft_strchr_variable(data->raw_cmd))
		data->raw_cmd = ft_parse_variables(data);

	if (ft_isallspace(data->raw_cmd))
	{
 		free(data->raw_cmd);
		return (0);
	}

	//one and multiple commands
	if (data->nbr_of_cmds == 1)
	{
		ft_init_data_one_cmd(data);
		ft_one_command(data);
		ft_free_one(data);
	}
	else if (data->nbr_of_cmds > 1)
	{
		ft_multiple_commands(data);
		free(data->raw_cmd);
	}
	return (0);
}
