/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:16:35 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/26 02:50:46 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_len_next_string(char *s, int c)
{
	int		i;
	int		d_quotes;
	int		s_quotes;

	i = 0;
	d_quotes = 0;
	s_quotes = 0;
	while (s[i])
	{
		if (s[i] == '\"' && !s_quotes)
			d_quotes++;
		if (s[i] == '\'' && !d_quotes)
			s_quotes++;
		if (s[i] == '\"' && d_quotes == 2)
			d_quotes = 0;
		if (s[i] == '\'' && s_quotes == 2)
			s_quotes = 0;
		if (s[i] == c && !d_quotes && !s_quotes)
			break ;
		i++;
	}
	return (i);
}

static char	*stringreturn(char const *s, char c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = ft_len_next_string((char *)s, c);
	str = ft_substr(s, 0, i);
	if (!str)
		return (NULL);
	return (str);
}

static char	**ft_free(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (NULL);
}

char	**ft_split_pipe(char const *s, int c)
{
	int		i;
	char	**ret;
	int		string;

	string = ft_count_commands((char *)s);
	i = 0;
	ret = malloc(sizeof(char *) * (string + 1));
	if (!ret || !s)
		return (NULL);
	while (i < string)
	{
		while (*s == c)
			s++;
		ret[i] = stringreturn(s, c);
		if (ret[i] == NULL)
			return (ft_free(ret, i));
		s += ft_strlen(ret[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
