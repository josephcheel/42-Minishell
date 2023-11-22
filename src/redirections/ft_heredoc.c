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


static void	ft_remove_heredoc_file(void)
{
	struct stat	buffer;

	if (access(HEREDOC_FILE, F_OK) != -1)
	{
		if (stat(HEREDOC_FILE, &buffer) == 0)
		{
			if (S_ISREG(buffer.st_mode))
				unlink(HEREDOC_FILE);
		}
		else
			perror ("stat");
	}
}

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
			if (temp->next)
			{
				ft_remove_heredoc_file();
				fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT | O_TRUNC , 0644);
				if (fd == -1)
					return (perror ("open"));
			}
			temp = temp->next;
		}
		else
			ft_putendl_fd(line, fd);
		free (line);
	}
	close (fd);
}

// search for END or IN

void	ft_heredoc(t_minishell *data)
{
	int		fd;
	t_list	*temp;

	signal(SIGINT, signal_handler_heredoc);
	signal(SIGQUIT, signal_handler_heredoc);
	fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (perror ("open"));
	temp = data->heredocs;
	ft_heredoc_loop(temp, fd);
}
