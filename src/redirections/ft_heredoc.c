#include "../../inc/minishell.h"

int ft_heredoc(t_minishell *data)
{
    int fd;
    char *line;
    t_list *temp;

    temp = data->heredocs;
    fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT , 0644);
    if (fd == -1) 
    {
        perror("open");
        return(1);
    }
    signal(SIGINT, signal_handler_heredoc);
	signal(SIGQUIT, signal_handler_heredoc);
    while(temp)
    {
        line = readline("> ");
        if (!line)
            break;
        if (strcmp(line, temp->content) == 0)
        {
           
           
            close(fd);
            fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT , 0644);
           	if (fd == -1) 
			{
				perror("open");
				return(1);
			}
			temp = temp->next;
        }
        else
        {
            ft_putstr_fd(line, fd);
            ft_putstr_fd("\n", fd);
        }
		free(line);
    }
    close(fd);
    // if (dup2(data->std_in, STDIN_FILENO) == -1)
	// 	    return (1);
    return(0);
}
