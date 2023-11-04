#include "../../inc/minishell.h"


/*
infile < ls > outfile1 > outfile2 file
ls file
*/

char *ft_clean_redir_cmd(char *str)
{
	int i;
	// int start;
	// int end;
	int double_q;
	int simple_q;

	i = 0;
	double_q = 0;
	simple_q = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i - 1] == ' ' && !double_q && !simple_q)
		{
		}
		else if (str[i] == '>' && str[i - 1] == ' ' && !double_q && !simple_q)
		{	
		}
		else if (str[i] == '>' && str[i - 1] == ' ' && str[i + 1] == '>' && !double_q && !simple_q)
		{
		}
		if (str[i] == '\"')
			double_q += 1;
		else if (str[i] == '\'')
			simple_q += 1;
		if (double_q == 2)
			double_q  = 0;
		else if (simple_q == 2)
			simple_q = 0;

	}	
	return (NULL);
}