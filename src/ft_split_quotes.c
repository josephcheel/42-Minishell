/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:39:00 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/09/16 01:06:23 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	**ft_free(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (NULL);
}


static char	*ft_substrfree(char const *s, unsigned int start,
		size_t len, int freeme)
{
	size_t	s_len;
	size_t	size;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (malloc(sizeof(char)));
	if (start + len > s_len)
		len = s_len - start;
	size = len + 1;
	str = (char *) malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	if (freeme == 1)
		free((void *)s);
	return (str);
}

static int	split_len(char *str)
{
	int	quote;
	int	i;

	i = 0;
	quote = 0;
	if (str[i] == 34)
		quote = 1;
	if (str[i] == 39)
		quote = 2;
	while (str[i])
	{
		if (str[i + 1] == 34 && str[i] != 92 && quote == 1)
			break ;
		if (str[i + 1] == 39 && str[i] != 92 && quote == 2)
			break ;
		if (str[i] == ' ' && quote == 0)
			break ;
		i++;
	}
	return (i);
}

static int	isnotquote(char *str, int i, int type)
{
	if (type == 1)
		type = 39;
	else if (type == 2)
		type = 34;
	if (str[i] != type || ((str[i] == type && str[i - 1] == 92) && str[i]))
		return (1);
	else
		return (0);
}

static int	ft_count_words(char *str, int words)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 39 && str[i - 1] != 92)
		{
			i++;
			while (isnotquote(str, i, 1))
				i++;
			words++;
		}
		else if (str[i] == 34 && str[i - 1] != 92)
		{
			i++;
			while (isnotquote(str, i, 2))
				i++;
			words++;
		}
		else if (str[i] != ' '
			&& (str[i + 1] == ' ' || str[i + 1] == '\0'))
			words++;
	}
	return (words);
}

static char	**alloc_split(char **split, char *str, int x)
{
	int	start;
	int	len;
	int	j;

	j = -1;
	start = 0;
	while (++j < x)
	{
		while (str[start] == ' ' && str[start])
			start++;
		printf("%c", str[start]);
		len = split_len(&str[start]);
		if ((str[start] == 34 || str[start] == 39) && str[start - 1] != 92)
			start++;
		split[j] = ft_substrfree(&str[start], 0, len, 0);
		if (!split[j])
			return (ft_free(split, j));
		start += len;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split_quotes(char *str)
{
	char	**split;
	int		x;

	x = ft_count_words(str, 0);
	printf("word: %d\n", x);
	split = malloc(sizeof(char *) * x + 1);
	if (!split)
		return (NULL);
	split = alloc_split(split, str, x);
	return (split);
}
