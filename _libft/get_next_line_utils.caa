/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:38:26 by ageiser           #+#    #+#             */
/*   Updated: 2022/12/14 14:56:17 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	else
	{
		ft_bzero(ptr, count * size);
		return (ptr);
	}
}
/*
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}		
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*soutput;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	soutput = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!soutput)
		return (NULL);
	while (s1[i])
	{
				soutput[j] = s1[i];
				i++;
				j++;
	}
				i = 0;
	while (s2[i])
	{
				soutput[j] = s2[i];
				i++;
				j++;
	}
				soutput[j] = '\0';
	return (soutput);
}
*/