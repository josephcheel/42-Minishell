/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:52:27 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/18 21:14:38 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
/*
** This function deletes all nodes of a list without
*/
void	ft_free_list(t_list **head)
{
	t_list	*temp;

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
}

static void	ft_free_multiple(t_minishell *data)
{
	if (data->raw_cmd)
		free(data->raw_cmd);
	if (data->mul_cmds)
		ft_array_free(data->mul_cmds, ft_array_size(data->mul_cmds));
	if (ft_lstsize(data->in_files) > 0)
		ft_free_list(&data->in_files);
	if (ft_lstsize(data->out_files) > 0)
		ft_free_list(&data->out_files);
	if (ft_lstsize(data->out_append) > 0)
		ft_free_list(&data->out_append);
	if (ft_lstsize(data->heredocs) > 0)
		ft_free_list(&data->heredocs);
}

int	ft_commands(t_minishell *data)
{
	data->nbr_of_cmds = ft_count_commands(data->raw_cmd);
	if (ft_syntax_errors(data))
		return (0);
	while (ft_strchr_variable(data->raw_cmd))
		data->raw_cmd = ft_parse_variables(data);
	if (ft_isallspace(data->raw_cmd))
	{
		free(data->raw_cmd);
		return (0);
	}
	if (data->nbr_of_cmds == 1)
	{
		ft_init_data_one_cmd(data);
		ft_one_command(data);
		ft_free_one(data);
	}
	else if (data->nbr_of_cmds > 1)
	{
		ft_init_data_multiple_cmds(data);
		ft_multiple_commands(data);
		ft_free_multiple(data);
	}
	return (0);
}
