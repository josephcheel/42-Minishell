/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_filename.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:01:38 by ageiser           #+#    #+#             */
/*   Updated: 2023/11/16 20:01:42 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_get_next_filename(char *raw_cmd)
{
	char	**split;
	char	*filename;

	while (*raw_cmd == '<' || *raw_cmd == '>')
		raw_cmd++;
	// while (ft_isspace(raw_cmd[i]))
	// 	i++;
	// printf("%s\n", raw_cmd);
//  return NULL;
	split = ft_split_quotes(raw_cmd);
	if (!split)
		return (NULL);
	filename = ft_strdup(split[0]);
	ft_array_free(split, ft_array_size(split));
	return (filename);
}
