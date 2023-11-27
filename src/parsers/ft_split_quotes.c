/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:40:46 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/23 00:41:28 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/split_quotes.h"
#include <stdio.h>

static char	**alloc_split_quotes(int size, char *str,
	char **split, t_quote *quotes)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = -1;
	start = 0;
	while (str[i] == ' ')
		i++;
	start = i;
	while (str[i] && ++j < size)
	{
		if (!ft_isspace(str[i]))
		{
			i = ft_get_final_quote(str, i, quotes);
			split[j] = ft_substr_split_quotes(str, i, start, j);
			while (ft_strlen(str) > (size_t)i && str[i + 1] == ' ')
				i++;
			if (!str[i])
				return (split);
			start = i;
		}
		i++;
	}
	return (split);
}

static int	ft_size_word(char *str)
{
	int		i;
	int		count;
	t_quote	quotes;

	i = -1;
	count = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	while (str[++i])
	{
		ft_get_quotes_values(str[i], &quotes);
		if ((str[i] == '\"' && !quotes.simple)
			|| (str[i] == '\'' && !quotes.dbl))
			;
		else
			count++;
	}
	return (count);
}

static char	*ft_copy_word(char *str, int size)
{
	int		i;
	int		count;
	char	*new_str;
	t_quote	quotes;

	i = -1;
	count = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	new_str = malloc(sizeof(char) * (size + 1));
	while (str[++i])
	{
		ft_get_quotes_values(str[i], &quotes);
		if ((str[i] == '\"' && !quotes.simple)
			|| (str[i] == '\'' && !quotes.dbl))
			;
		else
		{
			new_str[count] = str[i];
			count++;
		}
	}
	new_str[size] = '\0';
	return (new_str);
}

static void	ft_clean_split(char **split)
{
	int		i;
	int		x;
	int		size;
	char	*new_str;

	i = 0;
	x = 0;
	size = ft_array_size(split);
	while (i < size)
	{
		if (ft_strchr(split[i], '\'') || ft_strchr(split[i], '\"'))
		{
			x = ft_size_word(split[i]);
			new_str = ft_copy_word(split[i], x);
			free(split[i]);
			split[i] = new_str;
		}
		i++;
	}
}

char	**ft_split_quotes(char *str)
{
	int		size;
	char	**split;
	t_quote	quotes;

	quotes.dbl = 0;
	quotes.simple = 0;
	size = ft_count_words(str);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	split[size] = NULL;
	split = alloc_split_quotes(size, str, split, &quotes);
	ft_clean_split(split);
	return (split);
}
