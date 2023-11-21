/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacevar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:21:38 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/21 01:54:34 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*ft_alloc_replacer(char *replacer, char *before, char *after)
{
	char	*new_str;

	if (ft_strlen(replacer))
	{
		new_str = ft_strjoin(before, replacer);
		new_str = ft_strjoinfree(new_str, after);
	}
	else
	{
		if (ft_strlen(after))
			new_str = ft_strjoin(before, after);
		else
		{
			free(after);
			return (before);
		}
	}
	free(after);
	free(before);
	return (new_str);
}

char	*ft_replace_string(char *str, char *replace, char *replacer)
{
	char	*before_rp;
	char	*after_rp;
	char	*new_str;
	size_t	before_len;
	size_t	after_len;

	new_str = NULL;
	before_len = ft_strchr_variable(str) - str;
	after_len = ft_strlen(ft_strchr_variable(str) + ft_strlen(replace));
	before_rp = ft_substr(str, 0, before_len);
	after_rp = ft_substr(str, before_len + ft_strlen(replace) + 1, after_len);
	new_str = ft_alloc_replacer(replacer, before_rp, after_rp);
	return (new_str);
}
