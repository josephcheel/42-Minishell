/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:40:46 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/22 22:50:55 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/split_quotes.h"

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

int	ft_count_words(char *str)
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

char	*ft_substr_split_quotes(char *str, int i, int start, int j)
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

int	ft_get_final_quote(char *str, int i, t_quote *quotes)
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
