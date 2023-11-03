/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacevar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:21:38 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/03 01:45:34 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// static void ft_replace_string_free(char *before, char *after, char *new_str)
// {
// 	if (after)
// 		free(after);
// }

char	*ft_replace_string(char *str, char *replace, char *replacer)
{
	char	*before_rp;
	char	*after_rp;
	char	*new_str;
	size_t	before_len;
	size_t	after_len;

	before_len = ft_strchr_variable(str) - str;
	after_len = ft_strlen(ft_strchr_variable(str) + ft_strlen(replace));
	before_rp = ft_substr(str, 0, before_len);
	after_rp = ft_substr(str, before_len + ft_strlen(replace) + 1, after_len);
	new_str = NULL;
	if (ft_strlen(replacer))
	{
		new_str = ft_strjoin(before_rp, replacer);
		new_str = ft_strjoinfree(new_str, after_rp);
	}
	else
	{
		if (ft_strlen(after_rp))
			new_str = ft_strjoin(before_rp, after_rp);
		else
		{
			free(after_rp);
			return (before_rp);
		}
	}
	free(after_rp);
	free(before_rp);
	return (new_str);
}
