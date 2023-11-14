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

static char *quotes_substr(char *str, int start, int len)
{
	char *new_str;
	printf("START %d\n", start);
	while (str[start+1] == ' ')
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
	// while (str[start] == ' ')
	// 	start++;
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
				split[count] = quotes_substr(str, start, i+1);
			else if (str[i] == ' ')
				split[count] = quotes_substr(str, start, i);
			count++;
			if (size <= count)
				break ;
			start = i+ 1;
		}
		i++;
	}
	return (split);
}

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
		i++;
	}
	return (len);
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
	// printf("new %s\n", new_str);
	return (new_str);
}
static char **ft_clean_split(char **split)
{
	int i;
	int x;
	int size;
	char **new_str; 
	
	i = 0;
	x = 0;
	size = ft_array_size(split);
	new_str = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		if (ft_strchr(split[i], '\'') || ft_strchr(split[i], '\"'))
		{
			x = ft_size_word(split[i]);
			new_str[i] = ft_copy_word(split[i], x);
		}
		else 
			new_str[i] = ft_substr_free(split[i], 0, ft_strlen(split[i]), 0);
		i++;
	}
	new_str[size] = NULL;
	return (new_str);
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
	return (0);
	split = alloc_split_quotes(size, str, split);
	// new_split = ft_clean_split(split);
	// ft_array_free(split, ft_array_size(split)-1);
	return (split);
}

int main(int ac, char **av)
{
// 	// char *str = ft_strdup("echo \"adios\"\"adios\" adios\"sfjsak\" \"echo adios bondia\" \"   \"");
	// char *str = ft_strdup("echo  \"adios\" ");
	// char *str = ft_strdup("echo adios\"safsafl\"");
	// char *str = "echo \"adios\"";
	char **split;
	// char **cleaned;
	if (ac < 2)
		return 0;
	printf("STRING\t$%s$\n", av[1]);
	
	split = ft_split_quotes(av[1]);
	return (0);
	// cleaned = ft_clean_split(split);
	printf("$%s$\n", split[0]);
	printf("$%s$\n", split[1]);
	// printf("$%s$\n", cleaned[0]);
	// printf("$%s$\n", cleaned[1]);
	// free(str);
	ft_array_free(split, ft_array_size(split));
	// ft_array_free(cleaned, ft_array_size(cleaned));
	// if (split && split[0])
	// 	printf("$%s$\n", split[0]);

	// if (split && split[4])
	// 	printf("$%s$\n", split[4]);
}