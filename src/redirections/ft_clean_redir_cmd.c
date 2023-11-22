/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_redir_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:47:25 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/23 00:21:30 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
infile < ls > outfile1 > outfile2 file
ls file
*/

static int	get_end_redir(char *str, int start)
{
	while (str[start])
	{
		while (str[start] == '<' || str[start] == '>')
			start++;
		while (str[start] == ' ')
			start++;
		while (!ft_isspace(str[start]) && str[start + 1] != '\0')
			start++;
		while (str[start] == ' ' && str[start + 1] != '\0')
			start++;
		if (str[start + 1] == '\0')
			return (start + 1);
		if (str[start] == '<' || str[start] == '>')
			start++;
		else
			return (start);
	}
	return (start);
}

char	*ft_remove_redir(char *str, int start)
{
	int		len;
	int		end;
	char	*cleaned;
	char	*temp;
	char	*temp2;

	end = 0;
	len = ft_strlen(str);
	// printf("%s\n", &str[start]);
	end = get_end_redir(str, start);
	if (start == 0)
		cleaned = ft_substr(str, end, len);
	else if (end == len)
		cleaned = ft_substr(str, 0, start);
	else
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

char	*ft_clean_redir_cmd(char *str)
{
	int		i;
	t_quote	quotes;
	char	*cleaned;

	i = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	cleaned = ft_strdup(str);
	while (cleaned[i])
	{
		ft_get_quotes_values(cleaned[i], &quotes);
		if ((cleaned[i] == '<' || cleaned[i] == '>' )
			&& !quotes.dbl && !quotes.simple)
		{
			// if (cleaned[i + 1] == '<' || cleaned[i + 1] == '>' )
			// 	i++;
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
