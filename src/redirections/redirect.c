#include "../../inc/minishell.h"

void    in_file_top(char *filename) // >
{
    int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) 
	{
		perror("open");
		exit(1);
	}
    if (dup2(fd, STDOUT_FILENO) == -1) 
	{
		perror("dup2");
		exit(1);
	}
    close(fd);
    
}

void in_file_bottom(char *filename) // >>
{
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) 
    {
        perror("open");
        exit(1);
    }
    if (dup2(fd, STDOUT_FILENO) == -1) 
    {
        perror("dup2");
        exit(1);
    }
    close(fd);
}

void from_file_top(char *filename) // <
{
    int fd;

    // printf("FILENAME $%s$\n", filename);
    fd = open(filename, O_RDONLY);
    if (fd == -1) 
    {
        perror("open");
        exit(1);
    }
    if (dup2(fd, STDIN_FILENO) == -1) 
    {
        perror("dup2");
        exit(1);
    }
    close(fd);
}

void from_file_bottom(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1) 
    {
        perror("open");
        exit(1);
    }
    if (dup2(fd, STDIN_FILENO) == -1) 
    {
        perror("dup2");
        exit(1);
    }
    close(fd);
}

int ft_redirect(t_minishell *data) // return int // control this case 'ls <<<' or 'ls >>>'
{
    if (ft_permission_files_in(&data->in_files))
        return (1);
    // if (ft_open_files_out())

	// if (!data->infile && !data->out_files && !data->heredoc)
	// 	return (0);
	
	// if (data->infile)
	// 	printf("INFILE : %s\n", data->infile);
	// if( data->outfile)
	// 	printf("OUTFILE : $%s$\n", data->outfile);
	// if (data->heredoc)
	// 	printf("HEREDOC : %s\n", data->heredoc);
	// t_list *temp;
	
	// temp = data->out_append;

	// while (temp)
	// {
	// 	printf("APPEND %s\n", (char *)temp->content);
	// 	temp = temp->next;
	// }
	// printf("APPEND %s\n", data->outfile);
	if (data->outfile && !data->is_append)
		in_file_top(data->outfile);
	else if (data->outfile && data->is_append)
		in_file_bottom(data->outfile);
	if (data->infile)
		from_file_top(data->infile);
	if (data->infile)
		from_file_bottom(data->infile);
	if (data->heredoc && data->is_heredoc)
	{
	}
	return(0);
}
