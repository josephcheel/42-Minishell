#include "../../inc/minishell.h"

char *get_filename(char *raw_cmd, t_minishell *data) 
{
unsigned int start;
unsigned int stop;
unsigned int res;

start = 0;
stop = 0;
res = 0;
int i = 0;
// filename = NULL;

// filename = malloc(sizeof(ft_strlen(start)) + 1 );
// Avoid interpreting redirection in QUOTES  
    while (raw_cmd[i]) 
    {
        if (raw_cmd[i] == '<' || raw_cmd[i] == '>') // add >>
        {
            start = i +1;
            while(raw_cmd[start] == ' ') // start + 1 // echo hola > ./text.txt
                start++;
            stop = start;
            while(raw_cmd[stop + 1] != ' ')
                stop++;
            res = stop - start + 1;
            if (raw_cmd[i] == '<' )
            	data->infile = ft_substr(raw_cmd, start, res);
            else if (raw_cmd[i] == '>') 
        		data->outfile = ft_substr(raw_cmd, start, res);
        }
        i++;
    }
    // printf("%s\n", raw_cmd);
    // printf("%s\n", &raw_cmd[start]);
    // printf("$%d$\n", start);
    // printf("$%d$\n", stop);
    // printf("$%d$\n", res);
	
    //  data->infile = NULL 
    //  data->outfile = NULL
    if (data->infile)
        printf("INFILE %s\n", data->infile);
     if (data->outfile)
        printf("OUTFILE %s\n", data->outfile);
//     if (filename == NULL)
// {
//     perror("malloc filename");
//     exit(1);
// }
// (void)data;
    // while (start[j] != ) 
    // {
    //     filename[j] = start[j];
    //     j++;
    // }
    // filename[j] = '\0';
    
    // data->filename = filename;  
    //printf("%s", data->filename);
    return (NULL);
}

