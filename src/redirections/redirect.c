#include "../../inc/minishell.h"

void    in_file_top(char *filename)
{
    int fd;

    printf("FILENAME $%s$\n", filename);
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
	// close();
}

void in_file_bottom(char *filename)
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

void from_file_top(char *filename)
{
    int fd;

    printf("FILENAME $%s$\n", filename);
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

int ft_redirect(char	*raw_cmd, t_minishell *data) // return int // control this case 'ls <<<' or 'ls >>>'
{
    int i;
    i = 0;
    //ft_putstr_fd("is_redirect", 2);
    // char *filename;
    get_filename(raw_cmd, data);
    // data.filename = filename;  
    //printf("%s", data.filename);
    
	// access(filename, W_OK);
    while(raw_cmd[i])
    {
        if (raw_cmd[i] == '>' && raw_cmd[i + 1] != '>')
		{
			in_file_top(data->outfile);
			ft_putstr_fd("1", 2);
			// return(1);
		}
        else if (raw_cmd[i] == '>' && raw_cmd[i + 1] == '>')
		{
			in_file_bottom(data->outfile);
			ft_putstr_fd("2", 2);
			// return(2);
		}
        else if (raw_cmd[i] == '<' && raw_cmd[i + 1] != '<')
		{
			from_file_top(data->infile);
			ft_putstr_fd("3", 2);
			// return(3);
		}
        else if (raw_cmd[i] == '<'&& raw_cmd[i + 1] == '<')
		{
			from_file_bottom(data->infile);
			ft_putstr_fd("4", 2);
			// return(4);
		}
        
        i++;
    }
    return(i);
}
