/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:34 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/21 02:26:20 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_open_outfiles_loop(t_list *outfiles)
{
	int	fd;

	while (outfiles)
	{
		fd = open(outfiles->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror ("open");
			return (1);
		}
		close(fd);
		outfiles = outfiles->next;
	}
	return (0);
}

static int	ft_open_append_loop(t_list *append)
{
	int	fd;

	while (append)
	{
		fd = open(append->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror ("open");
			return (1);
		}
		close(fd);
		append = append->next;
	}
	return (0);
}

int	ft_open_files_out(t_minishell *data)
{
	t_list	*outfiles;
	t_list	*append;

	outfiles = data->out_files;
	append = data->out_append;
	if (ft_open_outfiles_loop(outfiles) || ft_open_append_loop(append))
		return (1);
	return (0);
}
