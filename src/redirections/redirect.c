#include "../../inc/minishell.h"

void    in_file_top(char *filename) // >
{
    int fd;

    // printf("HOLA");
    // printf("FILENAME $%s$\n", filename);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) 
	{
		perror("open");
		exit(1);
	}
    // close(fd);
    
    // fd = open(filename, O_WRONLY );
    // if (fd == -1) 
	// {
	// 	perror("open");
	// 	exit(1);
	// }
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

int ft_redirect(char	*raw_cmd, t_minishell *data) // return int // control this case 'ls <<<' or 'ls >>>'
{

    //ft_putstr_fd("is_redirect", 2);
    // char *filename;
    // return 0;
    if (ft_permission_files_in(&data->in_files))
		return (1);
	// if (ft_open_files_out())

	// printf("HOLA");
	// get_filename(raw_cmd, data);

	if (!data->infile && !data->out_files && !data->heredoc)
		return (0);
	
	// if (data->infile)
	// 	printf("INFILE : %s\n", data->infile);
	// if( data->outfile)
	// 	printf("OUTFILE : $%s$\n", data->outfile);
	// if (data->heredoc)
	// 	printf("HEREDOC : %s\n", data->heredoc);

	(void)raw_cmd;
	if (data->outfile && !data->is_append)
		in_file_top(data->outfile);
	else if (data->outfile && data->is_append)
		in_file_bottom(data->outfile);
	if (data->infile)
		from_file_top(data->infile);
	if (data->infile)
		from_file_bottom(data->infile);
    // while(raw_cmd[i])
    // {
		
    //     if (raw_cmd[i] == '>' && raw_cmd[i + 1] != '>')
	// 	{
	// 		in_file_top(data->outfile);
	// 		// ft_putstr_fd("1", 2);
	// 		// return(1);
	// 	}
    //     else if (raw_cmd[i] == '>' && raw_cmd[i + 1] == '>') //>>
	// 	{
	// 		i +=2 ;
	// 		// printf("DOUBEL >>\n");
	// 		in_file_bottom(data->outfile);
	// 		// ft_putstr_fd("2", 2);
	// 		// return(2);
	// 	}
    //     else if (raw_cmd[i] == '<' && raw_cmd[i + 1] != '<')
	// 	{
	// 		from_file_top(data->infile);
	// 		// ft_putstr_fd("3", 2);
	// 		// return(3);
	// 	}
    //     else if (raw_cmd[i] == '<'&& raw_cmd[i + 1] == '<')
	// 	{
	// 		from_file_bottom(data->infile);
	// 		// ft_putstr_fd("4", 2);
	// 		// return(4);
	// 	}
        
    //     i++;
    // }
    return(0);
}
