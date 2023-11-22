/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:40:46 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 14:23:05 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/split_quotes.h"
#include <stdio.h>

static int	ft_count_words_move_end(char *str, int i, t_quote *quotes)
{
	while ((ft_isprint(str[i]) && str[i] != ' ') && quotes->simple != -1
		&& quotes->dbl != -1 && str[i + 1] != '\0')
	{
		i++;
		ft_get_quotes_values(str[i], quotes);
		if (quotes->simple)
		{
			while (quotes->simple && str[i])
			{
				i++;
				ft_get_quotes_values(str[i], quotes);
			}
		}
		else if (quotes->dbl)
		{
			while (quotes->dbl && str[i])
			{
				i++;
				ft_get_quotes_values(str[i], quotes);
			}
		}
	}
	return (i);
}

static int	ft_count_words(char *str)
{
	int		i;
	int		len;
	t_quote	quotes;

	i = -1;
	len = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	while (str[++i])
	{
		ft_get_quotes_values(str[i], &quotes);
		if (ft_isprint(str[i]) && str[i] != ' '
			&& quotes.simple != 1 && quotes.dbl != 1)
		{
			len++;
			i = ft_count_words_move_end(str, i, &quotes);
		}
	}
	return (len);
}

static char	*ft_substr_split_quotes(char *str, int i, int start, int j)
{
	char	*new_str;

	if ((!ft_isstrprint(&str[i + 1]) && str[i] != ' ')
		&& (str[start] == '\'' || str[start] == '\"'))
		new_str = ft_substr(str, start, i - start + 1);
	else if (str[i + 1] == '\0' && !ft_isstrprint(&str[i + 1])
		&& (str[start] == '\'' || str[start] == '\"'))
		new_str = ft_substr(str, start, i - start);
	else if (j == 0)
		new_str = ft_substr(str, start, i - start);
	else if (str[i + 1] == '\0')
	{
		if (str[i] == ' ')
			new_str = ft_substr(str, start + 1, i - start - 1);
		else
			new_str = ft_substr(str, start + 1, i - 1);
	}
	else
		new_str = ft_substr(str, start + 1, i - start - 1);
	return (new_str);
}

static int	ft_get_final_quote(char *str, int i, t_quote *quotes)
{
	while (((ft_isprint(str[i]) && str[i] != ' ' && (!quotes->simple
					&& !quotes->dbl))) || (ft_isprint(str[i])
			&& (quotes->simple || quotes->dbl)))
	{
		ft_get_quotes_values(str[i], quotes);
		i++;
	}
	return (i);
}

static char	**alloc_split_quotes(int size, char *str, char **split)
{
	int		i;
	int		j;
	int		start;
	t_quote	quotes;

	i = 0;
	j = -1;
	start = 0;
	quotes.dbl = 0;
	quotes.simple = 0;
	while (str[i] == ' ')
		i++;
	start = i;
	while (str[i] && ++j < size)
	{
		if (ft_isprint(str[i]) && str[i] != ' ')
		{
			i = ft_get_final_quote(str, i, &quotes);
			split[j] = ft_substr_split_quotes(str, i, start, j);
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

	size = ft_count_words(str);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	split[size] = NULL;
	split = alloc_split_quotes(size, str, split);
	ft_clean_split(split);
	return (split);
}
