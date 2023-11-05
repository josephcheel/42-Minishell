#include "../../inc/minishell.h"


/*
infile < ls > outfile1 > outfile2 file
ls file
*/

static int	get_end_redir(char *str, int start)
{
	while (str[start])
	{
		if (str[start] != '<' || str[start] != '>')
			start++;
		while (str[start] == ' ')
			start++;
		while (ft_isalnum(str[start]) != 0)
			start++;
		while (str[start] == ' ')
			start++;
		if (str[start] == '<' || str[start] == '>')
			start++;
		else
			return (start);
	}
	return (start);
}

char *ft_remove_redir(char *str, int start)
{
	int len;
	int end;
	char *cleaned;
	char *temp;

	end = 0;
	len =ft_strlen(str);
	end = get_end_redir(str, start);

	if (start == 0)
	{
		cleaned = ft_substr(str, end, len);
		// free(str);
	}
	else if (end == len)
	{
		cleaned = ft_substr(str, 0, start);
		// free(str);
	}
	else // end in the middle
	{
		cleaned = ft_substr(str, 0, start);
		temp = ft_substr(str, end, len);
		cleaned = ft_strjoinfree(cleaned, temp);
		free(temp);
	}
	// printf("cleaned %s\n", cleaned);
	// free(str);
	return (cleaned);
}

char *ft_clean_redir_cmd(char *str)
{
	int i;
	int double_q;
	int simple_q;

	i = 0;
	double_q = 0;
	simple_q = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			double_q += 1;
		else if (str[i] == '\'')
			simple_q += 1;
		if (double_q == 2)
			double_q  = 0;
		else if (simple_q == 2)
			simple_q = 0;
		if (str[i] == '<' && !double_q && !simple_q)
		{
			str = ft_remove_redir(str, i);
			i = -1;
		}
		else if (str[i] == '>' && !double_q && !simple_q)
		{	
			str = ft_remove_redir(str, i);
			i = -1;
		}
		i++;
	}	
	return (str);
}

int main()
{
	// char *str = ft_strdup("< file1 ls < file2 > outfile file");
	char *str = ft_strdup("< file1 ls < file2 > outfile");
	// char *str = ft_strdup("< file1 ls");
	char *result;
	result = ft_clean_redir_cmd(str);
	printf("result $%s$\n", result);
	printf("str: $%s$\n", str);
	free(result);
	free(str);
}