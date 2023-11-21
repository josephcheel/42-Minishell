/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:07:49 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/21 02:16:33 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	ft_heredoc_loop(t_list *temp, int fd)
{
	char	*line;

	while (temp)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, temp->content) == 0)
		{
			close(fd);
			fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT, 0644);
			if (fd == -1)
				return (perror ("open"));
			temp = temp->next;
		}
		else
			ft_putendl_fd(line, fd);
		free (line);
	}
	close (fd);
}

void	ft_heredoc(t_minishell *data)
{
	int		fd;
	t_list	*temp;

	signal(SIGINT, signal_handler_heredoc);
	signal(SIGQUIT, signal_handler_heredoc);
	fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (perror ("open"));
	temp = data->heredocs;
	ft_heredoc_loop(temp, fd);
}
