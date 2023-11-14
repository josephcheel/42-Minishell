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
	return (ft_substr(str, start, len - start));
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
			while (str[start] == ' ')
					start++;
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
	t_quote quotes;

	i = 0;
	len = 0;
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
		if ((str[i] == ' ' || str[i] == '\0' ) && quotes.dbl == 0 && quotes.simple == 0 )
			len++;
		i++;
	}
	len++;
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
	char **new_split;
	
	size = ft_count_words(str);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return NULL;
	split = alloc_split_quotes(size, str, split);
	new_split = ft_clean_split(split);
	ft_array_free(split, ft_array_size(split)-1);
	return (new_split);
}

int main(void)
{
// 	// char *str = ft_strdup("echo \"adios\"\"adios\" adios\"sfjsak\" \"echo adios bondia\" \"   \"");
	// char *str = ft_strdup("echo \"adios\"");
	char *str = "echo \"adios\"";
	char **split;
	
	printf("STRING\t%s\n", str);
	
	split = ft_split_quotes(str);

	// if (split && split[0])
	// 	printf("$%s$\n", split[0]);

	// if (split && split[4])
	// 	printf("$%s$\n", split[4]);
}