/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:03:37 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/21 04:03:40 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_get_value_infile(t_minishell *data, char *raw_cmd)
{
	char	*filename;

	filename = ft_get_next_filename(raw_cmd);
	if (filename)
	{
		ft_redir_add_list(filename, &data->in_files);
		data->infile = filename;
	}
}

void	ft_get_value_outfile(t_minishell *data, char *raw_cmd)
{
	char	*filename;

	filename = ft_get_next_filename(raw_cmd);
	if (filename)
	{
		ft_redir_add_list(filename, &data->out_files);
		data->outfile = filename;
		data->is_append = 0;
	}
}

void	ft_get_value_append(t_minishell *data, char *raw_cmd)
{
	char	*filename;

	filename = ft_get_next_filename(raw_cmd);
	if (filename)
	{
		ft_redir_add_list(filename, &data->out_append);
		data->outfile = filename;
		data->is_append = 1;
	}
}

void	ft_get_value_heredoc(t_minishell *data, char *raw_cmd)
{
	char	*filename;

	filename = ft_get_next_filename(raw_cmd);
	if (filename)
	{
		ft_redir_add_list(filename, &data->heredocs);
		data->infile = HEREDOC_FILE;
		data->is_heredoc = 1;
	}
}
