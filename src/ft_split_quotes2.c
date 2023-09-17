#include <stdio.h>
#include <unistd.h>

#include "../inc/minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/split_quotes.h"

// static char	**ft_free(char **ret, int i)
// {
// 	while (i > 0)
// 		free(ret[--i]);
// 	free(ret);
// 	return (NULL);
// }

// static char	*ft_substrfree(char const *s, unsigned int start,
// 		size_t len, int freeme)
// {
// 	size_t	s_len;
// 	size_t	size;
// 	char	*str;

// 	if (!s)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	if (start > s_len)
// 		return (malloc(sizeof(char)));
// 	if (start + len > s_len)
// 		len = s_len - start;
// 	size = len + 1;
// 	str = (char *) malloc(size * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	ft_memcpy(str, s + start, len);
// 	str[len] = '\0';
// 	if (freeme == 1)
// 		free((void *)s);
// 	return (str);
// }

// int	split_len(char *str)
// {
// 	int	quote;
// 	int	i;

// 	i = 0;
// 	quote = 0;
// 	if (str[i] == 34)
// 		quote = 1;
// 	if (str[i] == 39)
// 		quote = 2;
// 	while (str[i])
// 	{
// 		if (str[i + 1] == 34 && str[i] != 92 && quote == 1)
// 			break ;
// 		if (str[i + 1] == 39 && str[i] != 92 && quote == 2)
// 			break ;
// 		if (str[i] == ' ' && quote == 0)
// 			break ;
// 		i++;
// 	}
// 	return (i);
// }


// char	**alloc_split(char **split, char *str, int x)
// {
// 	int	start;
// 	int	len;
// 	int	j;

// 	j = -1;
// 	start = 0;
// 	while (++j < x)
// 	{
// 		while (str[start] == ' ' && str[start])
// 			start++;
// 		len = split_len(&str[start]);
// 		printf("LEN : %d\n", len);
// 		while ((str[start] == 34 || str[start] == 39) && str[start - 1] != 92)
// 			start++;
// 		split[j] = ft_substrfree(&str[start], 0, len, 0);
// 		if (str[start + len] == '\"' || str[start + len] == '\'')
// 			start++;
// 		split[j] = ft_strtrim(split[j], " \n");
// 		if (!split[j])
// 			return (ft_free(split, j));
// 		start += len;
// 	}
// 	split[j] = NULL;
// 	return (split);
// }

// int	isnotquote(char *str, int i, int type)
// {
// 	if (str[i +1] == '\"' && str[i] == '\"')
// 		return 0;
// 	if (str[i] != type || ((str[i] == type && str[i - 1] == 92) && str[i]))
// 		return (1);
// 	else
// 		return (0);
// }

// int	ft_count_words(char *str, int words)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 	{
// 		if (str[i] == 39 && str[i - 1] != 92)
// 		{
// 			i++;
// 			while (isnotquote(str, i, '\"'))
// 				i++;
// 			words++;
// 		}
// 		else if (str[i] == 34 && str[i - 1] != 92)
// 		{
// 			i++;
// 			while (isnotquote(str, i, '\"'))
// 				i++;
// 			words++;
// 		}
// 		else if (str[i] != ' '
// 			&& (str[i + 1] == ' ' || str[i + 1] == '\0'))
// 			words++;
// 	}
// 	return (words);
// }

// int	ft_count_words(char *str)
// {
// 	int i;

// 	i = -1;
// 	while (str[++i])
// 	{

// 	}
// }

// char **ft_split_quotes(char *str)
// {
// 	t_split data;

// 	data.nbr_words = ft_count_words(str);
// 	data.split = (char **)malloc(sizeof(char *) * data.nbr_words + 1);
// 	if (!data.split)
// 		return (NULL);
// 	data.split = ft_alloc_words();
// 	return(data.split);
// }

/*
	check if theres doubled quotes in a string
*/
int	ft_has_valid_quotes(char *str) 
{
	int i;
	int simple_q;
	int	double_q;
	
	i = -1;
	simple_q = 0;
	double_q = 0;

	if (ft_strlen(str) == 0)
		return (1);
	while (str[++i])
	{
		if ((double_q % 2 == 0 || (double_q == 0 && simple_q != 0)) && (str[i] == '\'') && (str[i - 1] != '\\'))
			simple_q++;
		else if ((simple_q % 2 == 0 || (simple_q == 0 && double_q != 0)) && str[i] == '\"' && str[i - 1] != '\\')
			double_q++;
	}
	if (simple_q % 2 == 0 && double_q == 0)
		return (1);
	if (double_q % 2 == 0 && simple_q == 0)
		return (1);
	else
		return 0;
}

// int	main(int ac, char **av)
// {
// 	// if (ac != 2)
// 	// 	return 0;
//     // const char *bashCommand =  av[1];

//     // // Buffer to store the Bash command's output
//     // char buffer[128];
//     // memset(buffer, 0, sizeof(buffer));

//     // // Run the Bash command and capture its output
//     // FILE *fp = popen(bashCommand, "r");
//     // if (fp == NULL) {
//     //     perror("Failed to run Bash command");
//     //     return 1;
//     // }

//     // // Read the Bash command's output
//     // if (fgets(buffer, sizeof(buffer), fp) == NULL) {
//     //     perror("Failed to read Bash command output");
//     //     return 1;
//     // }

//     // // Close the file pointer
//     // pclose(fp);

//     // // Compare the output with a specific string
//     // const char *expectedOutput = "EXPECTED_STRING_HERE";
// 	// printf("BASH %s\n", buffer);
// 	// printf("HAS VALID QUOTES FUNC %d\n", ft_has_valid_quotes((char *)bashCommand));
//     // if (strcmp(buffer, expectedOutput) == 0) {
//     //     printf("Bash command output is the same as the expected string.\n");
//     // } else {
//     //     printf("Bash command output is different from the expected string.\n");
//     // }

// 	// char *str = "echo \'hola adios adios\'\"\'\"";
// 	if (ac != 2)
// 		return 0;
// 	char *str = av[1];
// 	printf("double quote string: $%s$, %d;\n1 == TRUE; 0 == FALSE\n", str, ft_has_valid_quotes(str));
// }