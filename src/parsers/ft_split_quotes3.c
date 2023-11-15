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
			quotes.simple = str[i];
		if (ft_isprint(str[i]) && str[i] != ' ')
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

static char **alloc_split_quotes(int size, char *str, char **split)
{
	int	i;
	int start;
	int count;
	t_quote quotes;


	i = 0;
	start = 0;
	count = 0;
	quotes.dbl = 0;
	quotes.simple = 0;

	while (str[i] == ' ')
			i++;
	start = i;
	while (str[i] != '\0')
	{
		
		if (str[i] == '\"' && quotes.simple == 0)
			quotes.dbl++;
		if (str[i] == '\'' && quotes.dbl == 0)
			quotes.simple++;
		if (str[i] == '\"' && quotes.dbl == 2)
			quotes.dbl = 0;
		if (str[i] == '\'' && quotes.simple == 2)
			quotes.simple = 0;
		if ((str[i] == ' ' || str[i+1] == '\0' )  && quotes.dbl == 0 && quotes.simple == 0 )
		{
			if (str[i+1] == '\0')
			{
				printf("EMPTY NEXT\n");
				split[count] = quotes_substr(str, start, i+1);
			}
			else if (str[i] == ' ')
			{
				printf("SPACE\n");
				split[count] = quotes_substr(str, start, i);
			}
			count++;
			if (size <= count)
				break ;
			start = i+ 1;
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
	
	split = ft_split_quotes(av[1]);
	// return (0);
	ft_clean_split(split);
	printf("$%s$\n", split[0]);
	printf("$%s$\n", split[1]);
	printf("$%s$\n", split[2]);
	printf("$%s$\n", split[3]);
	// free(str);
	// ft_array_free(split, ft_array_size(split));
	// ft_array_free(cleaned, ft_array_size(cleaned));
	// if (split && split[0])
	// 	printf("$%s$\n", split[0]);
	return (0);
	// if (split && split[4])
	// 	printf("$%s$\n", split[4]);
}