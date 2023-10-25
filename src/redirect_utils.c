#include "../inc/minishell.h"

char *get_filename(char *raw_cmd, size_t max_length, t_minishell data) 
{

char *filename;
filename = (char *)malloc(max_length);
const char *start;
start = NULL;
int i;
i = 0;
unsigned long j;
j = 0;
    
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
    while (start[j] && j < max_length - 1) 
    {
        filename[j] = start[j];
        j++;
    }
    filename[j] = '\0';
    
    data.filename = filename;  
    free(filename);
    return (0);
}

