/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:14:53 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/03 14:15:41 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (s != NULL && f != NULL)
	{
	i = ft_strlen(s);
		while (i2 < i)
		{
			f(i2, s);
		s++;
		i2++;
		}
	}	
}	
//ligne 15 fonction qui applique la fonction (f) a chaque [i]
//pas de retour de fonction
