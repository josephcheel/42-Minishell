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

// void from_file_bottom(char *filename)
// {
//     int fd;

//     fd = open(filename, O_RDONLY);
//     if (fd == -1) 
//     {
//         perror("open");
//         exit(1);
//     }
//     if (dup2(fd, STDIN_FILENO) == -1) 
//     {
//         perror("dup2");
//         exit(1);
//     }
//     close(fd);
// }

int ft_redirect(t_minishell *data) // return int // control this case 'ls <<<' or 'ls >>>'
{
    if (data->in_files && ft_permission_files_in(&data->in_files))
        return (1);
    if ((data->out_files || data->out_append) && ft_open_files_out(data))
        return (1);
     if (data->is_heredoc)
         ft_heredoc(data);
    if (data->infile)
    {
		// printf("INFILE : %s\n", data->infile);
        from_file_top(data->infile);
    }
	if (data->outfile && !data->is_append )
	{
        // printf("OUTFILE : $%s$\n", data->outfile);
        in_file_top(data->outfile);
    }
    else if (data->outfile && data->is_append)
		in_file_bottom(data->outfile);
    // if (data->infile)
	// 	from_file_bottom(data->infile);
	struct stat	buffer;

    if (access(HEREDOC_FILE, F_OK) != -1)
    {
        if (stat(HEREDOC_FILE, &buffer) == 0)
        {
            if (S_ISREG(buffer.st_mode))
                unlink(HEREDOC_FILE);
        }
        else
            perror("stat");
    }
	return(0);
}
