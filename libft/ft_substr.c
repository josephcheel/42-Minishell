/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:32 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/29 16:07:59 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*soutput;
	size_t			s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	soutput = (char *)malloc(sizeof(*s) * (len + 1));
	if (!soutput)
		return (NULL);
	ft_memcpy(soutput, s + start, len);
		soutput[len] = '\0';
	return (soutput);
}
//start =  val. comme [i]
//ligne 23 si start est plus grand que la longueur de s, retour vide
//ligne 25 si start + len est plus grand que 
//la longueur de s, longuer de len - start
//ligne 37 malloc de copie, de longueur len + '\0'
//ligne 30 (*soutput, *s + [start], longeur totale 
