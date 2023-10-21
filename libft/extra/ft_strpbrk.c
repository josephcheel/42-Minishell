/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:52:44 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 18:05:26 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
/* 
The strpbrk() function locates in the null-terminated string s
the first occurrence of any character in the string charset
and returns a pointer to this character.
If no characters from charset occur anywhere in s strpbrk() returns NULL.
*/
char	*ft_strpbrk(const char *s, const char *charset)
{
	while (s)
	{
		if (ft_strchr(charset, *s))
			return ((char *)s);
		s++;
	}
	return (NULL);
}
