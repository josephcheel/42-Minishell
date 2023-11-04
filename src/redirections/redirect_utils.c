#include "../../inc/minishell.h"

char *get_filename(char *raw_cmd, t_minishell *data) 
{
unsigned int start;
unsigned int stop;
unsigned int res;
int s_quote;
int d_quote;
int i;

i = 0;
s_quote = 0;
d_quote = 0;
start = 0;
stop = 0;
res = 0;

// filename = NULL;

// filename = malloc(sizeof(ft_strlen(start)) + 1 );
// Avoid interpreting redirection in QUOTES  
    while (raw_cmd[i]) 
    {   
        if (raw_cmd[i] == '\"' && !s_quote)
			d_quote++;
		if (raw_cmd[i] == '\'' && !d_quote)
			s_quote++;
		if (raw_cmd[i] == '\"' && d_quote == 2)
			d_quote = 0;
		if (raw_cmd[i] == '\'' && s_quote == 2)
			s_quote = 0;
        if (raw_cmd[i] == '<' || raw_cmd[i] == '>') // << >>
            {
            start = i + 1;
            if (raw_cmd[i] == '<' && raw_cmd[i + 1] == '<')    
                start++;
            else if (raw_cmd[i] == '>' && raw_cmd[i + 1] == '>')
                start++;
            while(raw_cmd[start] == ' ')
                start++;
            stop = start;
            while(raw_cmd[stop] != ' ' && raw_cmd[stop] != '\0')
                stop++;
            res = stop - start;
            if (raw_cmd[i] == '<')
            {
                if (data->infile)
                    free(data->infile);
                data->infile = ft_substr(raw_cmd, start, res);
            }
            else if (raw_cmd[i] == '>') 
            {
                if(data->outfile)
                    free(data->outfile);
        		data->outfile = ft_substr(raw_cmd, start, res);
            }
            i = stop;
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

