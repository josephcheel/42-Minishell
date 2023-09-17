/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:38:14 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/09/17 02:11:36 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}	
	else if (src < dst)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	return (dst);
}
