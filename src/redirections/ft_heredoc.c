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

    while(temp)
    {
        line = readline("> ");
        if (strcmp(line, temp->content) == 0)
        {
           
            if (!line)
                break;
            close(fd);
            fd = open(HEREDOC_FILE, O_WRONLY | O_CREAT , 0644);
            line = temp->content;
            temp = temp->next;
          //  printf("minishell HEREDOC %s\n", temp->content);
          //  printf("minishell HEREDOC %s\n", (char *)temp->next->content);


           
            free(line);
        }
        else
        {
            ft_putstr_fd(line, fd);
            ft_putstr_fd("\n", fd);
        }
    }
     close(fd);
    // unlink(HEREDOC_FILE);
    return(0);
}
