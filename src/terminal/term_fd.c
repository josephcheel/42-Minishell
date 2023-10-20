/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:35:33 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 03:36:15 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	init_term_fd(t_minishell *data)
{
	data->std_in = dup(STDIN_FILENO);
	data->std_out = dup(STDOUT_FILENO);
	if (data->std_in == -1 || data->std_out == -1)
	{
		perror("dup");
		return (1);
	}
	return (0);
}

int	reset_term_fd(t_minishell *data)
{
	if (dup2(data->std_in, STDIN_FILENO) == -1)
		return (1);
	if (dup2(data->std_out, STDIN_FILENO) == -1)
		return (1);
	return (0);
}

int	close_term_fd(t_minishell *data)
{
	if (close(data->std_in) == -1)
		return (1);
	if (close(data->std_out) == -1)
		return (1);
	return (0);
}
