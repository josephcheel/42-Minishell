/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_filename.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:01:38 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/20 20:27:52 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_get_next_filename(char *raw_cmd)
{
	char	**split;
	char	*filename;

	while (*raw_cmd == '<' || *raw_cmd == '>')
		raw_cmd++;
	split = ft_split_quotes(raw_cmd);
	if (!split)
		return (NULL);
	filename = ft_strdup(split[0]);
	ft_array_free(split, ft_array_size(split));
	return (filename);
}
