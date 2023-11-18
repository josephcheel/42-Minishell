/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:01:50 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/18 21:09:05 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_syntax_errors(t_minishell *data)
{
	if (ft_has_valid_quotes(data->raw_cmd) == 0)
	{
		free(data->raw_cmd);
		return (write(2, "quote>\n", 8));
	}
	if (data->nbr_of_cmds > 1 && ft_check_pipe_sytax(data))
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
