/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:53:01 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/01 12:52:37 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
			i++;
	}		
	return (0);
}	

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	begin;
	size_t	end;
	char	*soutput;

	i = 0;
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] != '\0' && is_in_set(s1[begin], set))
		begin++;
	while (end > begin && is_in_set(s1[end - 1], set))
		end--;
	soutput = malloc(sizeof(char) * (end - begin + 1));
	if (soutput == NULL)
		return (NULL);
	while (begin < end)
		soutput[i++] = s1[begin++];
	soutput[i] = 0;
	return (soutput);
}
//ligne 15 fonction statique qui cherche dans (c) si il y a un char de (set)
//linge 38 longueur totale de (s1)
//ligne 39 tant que (s1) et qu'il y a un char de (set) dans (s1), begin++
//ligne 41 tant que la longueur de (end) est plus grande que la longueur de 
//(begin) et qu'il y a un char de (set) dans (s1), end --    
//ligne 41 ([end -1] === lg de (s1) - '\0') 
//ligne 43 creation du malloc
//ligne 46 tant que (begin) est plus petit que (end), 
//copie de (s1) dans (soutput)
//ligne 48 on reinitilalise (soutput) a 0  
