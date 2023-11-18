#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../libft/inc/libft.h"

typedef struct s_quote{

	int dbl;
	int	simple;
	int long_malloc;

}t_quote;

static int ft_count_words(char *str)
{
	int	i;
	int len;
	int in_word;
	t_quote quotes;

	i = 0;
	len = 0;
	in_word = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	while (str[i])
	{
		if (str[i] == '\"' && quotes.simple == 0)
			quotes.dbl++;
		if (str[i] == '\'' && quotes.dbl == 0)
			quotes.simple++;
		if (str[i] == '\"' && quotes.dbl == 2)
			quotes.dbl = 0;
		if (str[i] == '\'' && quotes.simple == 2)
			quotes.simple = 0;
		if (ft_isprint(str[i]) && str[i] != ' ' && quotes.simple == 0 && quotes.dbl == 0)
		{
			len++;
			while (((ft_isprint(str[i]) && str[i] != ' ') || str[i] == '\''  || str[i] == '\"')&& str[i+1] != '\0')
				i++;
		}
		i++;
	}
	return (len);
}

static char *quotes_substr(char *str, int start, int len)
{
	char *new_str;

	printf("START %d LEN %d\n", start, len);
	while (str[start] == ' ')
		start++;
	new_str = ft_substr(str, start, len - start);
	return (new_str);
}

// static char **alloc_split_quotes(int size, char *str, char **split)
// {
// 	int	i;
// 	int start;
// 	int count;
// 	t_quote quotes;


// 	i = 0;
// 	start = 0;
// 	count = 0;
// 	quotes.dbl = 0;
// 	quotes.simple = 0;

// 	while (str[i] == ' ')
// 			i++;
// 	start = i;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '\"' && quotes.simple == 0)
// 			quotes.dbl++;
// 		if (str[i] == '\'' && quotes.dbl == 0)
// 			quotes.simple++;
// 		if (quotes.dbl == 2)
// 			quotes.dbl = 0;
// 		if (quotes.simple == 2)
// 			quotes.simple = 0;
// 		printf("%s, simple %d double %d\n", &str[i], quotes.simple, quotes.dbl);
// 		if ((str[i] == ' ' || str[i+1] == '\0')  && quotes.simple == 0 && quotes.dbl == 0)
// 		{
// 			if (str[i+1] == '\0')
// 			{
// 				while (str[i] == ' ')
// 					i--;
// 				printf("EMPTY NEXT\n");
// 				split[count] = quotes_substr(str, start, i+1);
// 			}
// 			else if (str[i] == ' ')
// 			{
// 				printf("SPACE\n");
// 				split[count] = quotes_substr(str, start, i);
// 			}
// 			count++;
// 			if (size < count)
// 				break ;
// 			start = i;

// 		}
// 		else if ((str[i] == ' ' || str[i+1] == '\0') && (!quotes.simple && quotes.dbl || !quotes.dbl && quotes.dbl) )
// 		{
// 			printf("AAA%s, simple %d double %d\n", &str[i], quotes.simple, quotes.dbl);
// 			split[count] = quotes_substr(str, start, i);
// 			count++;
// 			// if (str[i+1] == '\0')
// 			// {
// 			// 	while (str[i] == ' ')
// 			// 		i--;
// 			// 	printf("EMPTY NEXT\n");
// 			// 	split[count] = quotes_substr(str, start, i+1);
// 			// }
// 			// else if (str[i] == ' ')
// 			// {
// 			// 	printf("SPACE\n");
// 			// 	split[count] = quotes_substr(str, start, i);
// 			// }
// 			// count++;
// 			// if (size < count)
// 			// 	break ;
// 			// start = i;
// 		}
// 		while (str[i] == ' ')
// 			i++;
// 		i++;
// 	}
// 	return (split);
// }

static char **alloc_split_quotes(int size, char *str, char **split)
{
	int	i;
	int j;
	int start;
	int in_word;
	t_quote quotes;

	i = 0;
	j = 0;
	start = 0;
	in_word = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	while (str[i] == ' ')
		i++;
	start = i;
	while (str[i] && j < size) 
	{
		if (ft_isprint(str[i]) && str[i] != ' ')// && quotes.simple != 1 && quotes.dbl != 1)// || quotes.simple == 1 && quotes.dbl == 1)
		{
			// start = i;
			// while ((ft_isprint(str[i]) && str[i] != ' ')||( str[i] == '\'' && !quotes.dbl)|| (str[i] == '\"' && !quotes.simple)&& str[i+1] != '\0')
			// while ((ft_isprint(str[i]) && str[i] != ' ') || ((str[i] == '\"' && !quotes.simple  || str[i] == '\''  && !quotes.dbl )) && str[i+1] != '\0')
			// printf("STRING : $");
			while (((ft_isprint(str[i]) && str[i] != ' ' && (!quotes.simple && !quotes.dbl ))) || ft_isprint(str[i]) && (quotes.simple || quotes.dbl))
			{
				// printf("SIMPLE %d, DOUBLE %d\n", quotes.simple, quotes.dbl);
				// printf("%c\n", str[i]);
				if (str[i] == '\"' && quotes.simple == 0)
					quotes.dbl++;
				if (str[i] == '\'' && quotes.dbl == 0)
					quotes.simple++;
				if (str[i] == '\"' && quotes.dbl == 2)
					quotes.dbl = 0;
				if (str[i] == '\'' && quotes.simple == 2)
					quotes.simple = 0;
				i++;
			}
			printf("\n");
			printf("start %c[%d] END %c[%d]\n", str[start], start, str[i], i);
			if ((!ft_isstrprint(&str[i+1]) && str[i] != ' ')&& (str[start] == '\'' || str[start] == '\"'))
			{
				printf("1 %d\n", j);
				split[j] = ft_substr(str, start, i- start+1);
			}
			else if (str[i+1] == '\0' && !ft_isstrprint(&str[i+1]) && (str[start] == '\'' || str[start] == '\"'))
			{
				printf("2 %d\n", j);
				printf("SIMPLE %d, DOUBLE %d\n", quotes.simple, quotes.dbl);
				split[j] = ft_substr(str, start, i - start);
				// else
				// 	split[j] = ft_substr(str, start, i - start-1);
			}
			else if (str[i+1] == '\0')
			{
				printf("7 %d\n", j);
					printf("HOLIA start %c[%d] END %c[%d]\n", str[start], start, str[i], i);
				printf("STRING $%s$\n", &str[i]);
				if (str[i] == ' ')
				{
					printf("HOLAI\n");
					split[j] = ft_substr(str, start+1, i - start-1);
				}
				else
				{
					printf("ADEUII\n");
					split[j] = ft_substr(str, start, i-1);
				}
			}
			else if (j == 0)
			{
				printf("3 %d\n", j);
				split[j] = ft_substr(str, start, i- start);
			}
			else
			{
				printf("SIMPLE %d, DOUBLE %d\n", quotes.simple, quotes.dbl);
				printf("4 %d\n", j);
				split[j] = ft_substr(str, start+1, i - start-1);
			}
			j++;
			while (str[i+1] == ' ')
				i++;
			start = i;
			if (str[i] == '\"' && quotes.dbl == 1)
				quotes.dbl = 0;
			if (str[i] == '\'' && quotes.simple == 1)
				quotes.simple = 0;
		}
		i++;
	}
	return (split);

}

static int ft_size_word(char *str)
{
	int i;
	int count;
	t_quote quotes;

	i = 0;
	count = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	while (str[i])
	{
		if (str[i] == '\"' && quotes.simple == 0)
			quotes.dbl++;
		if (str[i] == '\'' && quotes.dbl == 0)
			quotes.simple++;
		if (str[i] == '\"' && quotes.dbl == 2)
			quotes.dbl = 0;
		if (str[i] == '\'' && quotes.simple == 2)
			quotes.simple = 0;
		if ((str[i] == '\"' && !quotes.simple ) || ( str[i] == '\'' && !quotes.dbl))
			;
		else
			count++;
		i++;
	}
	return (count);
}

static char *ft_copy_word(char *str, int size)
{
	int i;
	int count;
	char *new_str;
	t_quote quotes;

	i = 0;
	count = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	new_str = malloc(sizeof(char) * (size + 1));
	while (str[i])
	{
		if (str[i] == '\"' && quotes.simple == 0)
			quotes.dbl++;
		if (str[i] == '\'' && quotes.dbl == 0)
			quotes.simple++;
		if (str[i] == '\"' && quotes.dbl == 2)
			quotes.dbl = 0;
		if (str[i] == '\'' && quotes.simple == 2)
			quotes.simple = 0;
		if ((str[i] == '\"' && !quotes.simple ) || ( str[i] == '\'' && !quotes.dbl))
			;
		else
		{
			new_str[count] = str[i];
			count++;
		}
		i++;
	}
	new_str[size] = '\0';
	return (new_str);
}

static void ft_clean_split(char **split)
{
	int i;
	int x;
	int size;
	char *new_str; 
	
	i = 0;
	x = 0;
	while (i < size)
	{

		if (ft_strchr(split[i], '\'') || ft_strchr(split[i], '\"'))
		{
			x = ft_size_word(split[i]);
			new_str = ft_copy_word(split[i], x);
			free(split[i]);
			split[i] = new_str;
			// printf("new_str %s\n", new_str);
			// new_str[i] = ft_substr_free(split[i], 0, ft_strlen(split[i]), 0);
		}
		i++;
	}
}


char **ft_split_quotes(char *str)
{
	int size;
	char **split;
	// char **new_split;
	
	size = ft_count_words(str);

	printf("size %d\n", size);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return NULL;
	split[size] = NULL;
	// return (0);
	split = alloc_split_quotes(size, str, split);
	// new_split = ft_clean_split(split);
	// ft_array_free(split, ft_array_size(split)-1);
	return (split);
}

// NO_COLOR		=	\x1b[0m
// OK_COLOR		=	\x1b[32;01m
int main(int ac, char **av)
{
// 	// char *str = ft_strdup("echo \"adios\"\"adios\" adios\"sfjsak\" \"echo adios bondia\" \"   \"");
	// char *str = ft_strdup("echo  \"adios\" ");
	// char *str = ft_strdup("echo adios\"safsafl\"");
	// char *str = "echo \"adios\"";
	char **split;
	if (ac < 2)
		return 0;

	printf("STRING\t\x1b[32;01m$%s$\x1b[0m\n", av[1]);
	printf("SIZE %zu\n", ft_strlen(av[1]));
	split = ft_split_quotes(av[1]);
	// return (0);
	// ft_clean_split(split);
	int size = ft_array_size(split);
	printf("size size %d\n", size);
	if (size >= 0)
		printf("$%s$\n", split[0]);
	if (size >= 1)
		printf("$%s$\n", split[1]);
	if (size >= 2)
		printf("$%s$\n", split[2]);
	if (size >= 3)
		printf("$%s$\n", split[3]);
	// printf("$%s$\n", split[3]);
	// free(str);
	// ft_array_free(split, ft_array_size(split));
	ft_array_free(split, ft_array_size(split));
	// if (split && split[0])
	// 	printf("$%s$\n", split[0]);
	return (0);
	// if (split && split[4])
	// 	printf("$%s$\n", split[4]);
}