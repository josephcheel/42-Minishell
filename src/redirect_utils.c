#include "../inc/minishell.h"

char *get_filename(char *raw_cmd, t_minishell *data) 
{
const char *start;
start = NULL;
char *filename;
// filename = malloc(sizeof(ft_strlen(start)) + 1 );

int i;
i = 0;
unsigned long j;
j = 0;

if (filename == NULL)
{
    perror("malloc filname");
    exit(1);
}
    
    while (raw_cmd[i]) 
    {
        if (raw_cmd[i] == '<' || raw_cmd[i] == '>') {
            start = &raw_cmd[i + 1];
            break;
        }
        i++;
    }

    if (start == NULL) 
    {
        return (NULL);
    }
	filename = ft_substr(raw_cmd, start, ft_strlen(raw_cmd));
    // while (start[j]) 
    // {
    //     filename[j] = start[j];
    //     j++;
    // }
    // filename[j] = '\0';
    
    data->filename = filename;  
    //printf("%s", data->filename);
    return (filename);
}

