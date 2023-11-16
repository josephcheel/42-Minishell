/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:34 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/16 19:41:35 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_open_files_out(t_minishell *data)
{
	int		fd;
	t_list	*temp;
	t_list	*tmp;

	temp = data->out_files;
	tmp = data->out_append;
	while (temp)
	{
		fd = open(temp->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror ("open");
			return (1);
		}
		temp = temp->next;
		close(fd);
	}
	while (tmp)
	{
		fd = open(tmp->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror ("open");
			return (1);
		}
		tmp = tmp->next;
		close(fd);
	}
	return (0);
}
