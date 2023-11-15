#include "../../inc/minishell.h"

int ft_heredoc(t_minishell *data)
{
    int fd;
    char *line;
    t_list *temp;

    temp = data->heredocs;
    // printf("HEREDOC %s\n", temp->content);
    fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT , 0644);

    if (fd == -1) 
    {
        perror("open");
        return(1);
    }

    // signal(SIGINT, SIG_IGN);
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
            line = temp->content;
            temp = temp->next;
            free(line);
        }
        else
        {
            ft_putstr_fd(line, fd);
            ft_putstr_fd("\n", fd);
        }
    }
    close(fd);
    // if (dup2(data->std_in, STDIN_FILENO) == -1)
	// 	    return (1);
    return(0);
}
