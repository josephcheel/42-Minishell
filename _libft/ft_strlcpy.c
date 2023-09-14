/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:41:28 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/26 18:29:37 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{	
		while (src[i] != '\0' && i < (dstsize -1))
		{	
		dst[i] = src[i];
		i++;
		}
	dst[i] = 0;
	}
	while (src[i] != '\0')
		i++;
	return (i);
}	
