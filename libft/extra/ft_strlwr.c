/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlwr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:11:09 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 13:11:15 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strlwr(char *str)
{
	int		i;
	char	*new_str;

	new_str = ft_strdup(str);
	i = -1;
	if (!str || !new_str)
		return (NULL);
	while (str[++i])
		new_str[i] = ft_tolower(str[i]);
	return (new_str);
}
