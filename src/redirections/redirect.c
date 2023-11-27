/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:13:44 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/21 02:43:53 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	in_file_top(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror ("dup2");
		exit (1);
	}
	close (fd);
}

void	in_file_bottom(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror ("open");
		exit (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror ("dup2");
		exit (1);
	}
	close(fd);
}

void	from_file_top(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror ("dup2");
		exit (1);
	}
	close(fd);
}

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

int	ft_redirect(t_minishell *data)
{
	if ((data->out_files || data->out_append) && ft_open_files_out(data))
		return (1);
	if (data->in_files && ft_permission_files_in(&data->in_files))
		return (1);
	if (data->is_heredoc)
		ft_heredoc(data);
	if (data->infile)
		from_file_top(data->infile);
	if (data->outfile && !data->is_append)
		in_file_top(data->outfile);
	else if (data->outfile && data->is_append)
		in_file_bottom(data->outfile);
	ft_remove_heredoc_file();
	return (0);
}
