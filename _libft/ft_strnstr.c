/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:46:17 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/27 13:25:58 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{		
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			{		
				if (needle[j + 1] == '\0')
					return ((char *)(haystack + i));
			j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}	

//ligne 22 if (needle == NULL || needle[0] == '\0')
//ligne 30 dans le cas d une seule lettre needle
//ligne 32 plusieurs lettre needle
