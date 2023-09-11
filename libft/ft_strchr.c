/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:24:47 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/08 17:39:58 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i ;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (const char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (const char)c)
		return ((char *)s + i);
	return (NULL);
}
/*
  int main(void)
  {
	  const char s[] = "pleiades";
	  int c = 'e';

	  printf("strchr string lettre, %s 5c\n", s c);
	  printf("resultat: %s\n", ft_strchr(s, c));
	  return (0);
  }*/
//ligne 26 et 27 si \0
