/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:39:00 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/09/20 16:02:53 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/split_quotes.h"
#include "../../libft/inc/libft.h"

int	split_len(char *str)
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

int	isnotquote(char *str, int i, int type)
{
	if (str[i +1] == '\"' && str[i] == '\"')
		return 0;
	if (str[i] != type || ((str[i] == type && str[i - 1] == 92) && str[i]))
		return (1);
	else
		return (0);
}

int	ft_count_words(char *str, int words)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 39 && str[i - 1] != 92)
		{
			i++;
			while (isnotquote(str, i, '\"'))
				i++;
			words++;
		}
		else if (str[i] == 34 && str[i - 1] != 92)
		{
			i++;
			while (isnotquote(str, i, '\"'))
				i++;
			words++;
		}
		else if (str[i] != ' '
			&& (str[i + 1] == ' ' || str[i + 1] == '\0'))
			words++;
	}
	return (words);
}

char	**alloc_split(char **split, char *str, int x)
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
		len = split_len(&str[start]);
		while ((str[start] == 34 || str[start] == 39) && str[start - 1] != 92)
			start++;
		split[j] = ft_substr_free(&str[start], 0, len, 0);
		if (str[start + len] == '\"' || str[start + len] == '\'')
			start++;
		if (!split[j])
			return (ft_array_free(split, j));
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
	split = malloc(sizeof(char *) * x + 1);
	if (!split)
		return (NULL);
	split = alloc_split(split, str, x);
	return (split);
}
