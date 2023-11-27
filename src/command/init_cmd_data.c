/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:20:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/18 20:20:29 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_data_one_cmd(t_minishell *data)
{
	data->in_files = NULL;
	data->out_files = NULL;
	data->out_append = NULL;
	data->heredocs = NULL;
	data->infile = NULL;
	data->outfile = NULL;
	data->in_files = NULL;
	data->out_files = NULL;
	data->out_append = NULL;
	data->is_append = 0;
	data->is_heredoc = 0;
	ft_get_redit_value(data->raw_cmd, data);
	if (data->in_files || data->out_files || data->out_append || data->heredocs)
		data->cleaned_cmd = ft_clean_redir_cmd(data->raw_cmd);
	else
		data->cleaned_cmd = ft_strdup(data->raw_cmd);
	data->cmd = ft_split_quotes(data->cleaned_cmd);
}

void	ft_init_data_multiple_cmds(t_minishell *data)
{
	data->mul_cmds = ft_separate_cmds(data);
	data->in_files = NULL;
	data->out_files = NULL;
	data->out_append = NULL;
	data->heredocs = NULL;
	data->infile = NULL;
	data->outfile = NULL;
	data->in_files = NULL;
	data->out_files = NULL;
	data->out_append = NULL;
	data->is_append = 0;
	data->is_heredoc = 0;
}
