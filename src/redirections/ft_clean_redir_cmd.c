#include "../../inc/minishell.h"


/*
infile < ls > outfile1 > outfile2 file
ls file
*/

int ft_check_redir_sytax(char *str) // return OK(0) NOT_OK(1)
{
	int i;

	int len;
	int redir_left;
	int redir_right;
	

	i = 0;
	len = ft_strlen(str) - 1;
	redir_left = 0;
	redir_right = 0;
	while (str[i])
	{
		if (str[i] == '<' )
			redir_left++;
		else if ( str[i] == '>')
			redir_right++;
		if (ft_isspace(str[i]))
		{
			redir_left = 0;
			redir_right = 0;
		}
		if ((redir_left > 2 && !redir_right )||( redir_right > 2 && !redir_left))
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `>'\n", 2);
			return (1);
		}
		else if (redir_left && redir_right)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `>'\n", 2);
			return (1);
		}
		i++;
	}
	if (str[len] == ' ')
	{
		while (str[len] == ' ')
			len--;
		if (str[len] == '<' || str[len] == '>')
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
			return (1);
		}
	}
	if (str[ft_strlen(str) - 1] == '<' || str[ft_strlen(str) - 1] == '>')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
		return (1);
	}
	return (0);
}

static int	get_end_redir(char *str, int start)
{
	while (str[start])
	{
		if (str[start] != '<' || str[start] != '>')
			start++;
		while (str[start] == ' ')
			start++;
		while (!ft_isspace(str[start]) && str[start+1] != '\0')
			start++;
		while (str[start] == ' ' && str[start+1] != '\0')
			start++;
		if (str[start+1] == '\0')
			return (start+1);
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
	char *temp2;

	end = 0;
	len = ft_strlen(str);
	end = get_end_redir(str, start);
	if (start == 0)
		cleaned = ft_substr(str, end, len);
	else if (end == len)
		cleaned = ft_substr(str, 0, start);
	else // end in the middle
	{
		temp = ft_substr(str, 0, start);
		temp2 = ft_substr(str, end, len);
		cleaned = ft_strjoin(temp, temp2);
		free(temp);
		free(temp2);
	}

	if (str)
		free(str);
	return (cleaned);
}

char *ft_clean_redir_cmd(char *str)
{
	int i;
	int double_q;
	int simple_q;
	char *cleaned;

	i = 0;
	double_q = 0;
	simple_q = 0;
	cleaned = ft_strdup(str);
	while (cleaned[i])
	{
		if (cleaned[i] == '\"')
			double_q += 1;
		else if (cleaned[i] == '\'')
			simple_q += 1;
		if (double_q == 2)
			double_q  = 0;
		else if (simple_q == 2)
			simple_q = 0;
		if ((cleaned[i] == '<' || cleaned[i] == '>' ) && !double_q && !simple_q)
		{
			if (cleaned[i+1] == '<' || cleaned[i+1] == '>' )
				i++;
			cleaned = ft_remove_redir(cleaned, i);
			i = -1;
		}
		i++;
	}
	return (cleaned);
}

// int main()
// {
// 	// char *str = ft_strdup("< file1 ls < file2 > outfile file");
// 	// char *str = ft_strdup("< file1 ls < file2 > outfile");
// 	// char *str = ft_strdup("< file1 ls");
// 	char *str = ft_strdup("< infile grep a1 | wc -w > outfile");
// 	// char *str = "< infile grep a1 | wc -w > outfile";
// 	char *result;
// 	result = ft_clean_redir_cmd(str);
// 	printf("\x1b[32;01mresult $%s$\n", result);
// 	printf("str: $%s$\n\x1b[0m", str);
// 	free(result);
// 	// free(str);
// }