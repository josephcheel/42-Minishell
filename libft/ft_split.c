/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:07:55 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/07 15:57:23 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}	
//ligne 15 fonction qui compte le nombre de (c)
//Utilise pour le malloc de la fonction principale

static char	**freemalloc(char **str, size_t index)
{
	while (index-- > 0)
		free(str[index]);
	free(str);
	return (0);
}	

//ligne 15 fonctoin qui permet de liberer le malloc en cas de 
//disfonctionnement
//ligne 40 tant que index est plus grand que 0
//ligne 41 on libere ce qu'il y a dans le pointeur str et on se
//deplace d'une case
//ligne 42 on libere le malloc principal

static char	**pointerwriter(char **str, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			j = i + 1;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			str[index] = ft_substr(s, j, i - j + 1);
			if (!str[index])
			{
				return (freemalloc(str, index));
			}
			index++;
		}
		i++;
	}
	return (str);
}	

//ligne 53 fonction qui ecrit les mots dans les pointeurs
//ligne 62 tant qu'on est dans le string original
//ligne 64 si s[i] correspont au caractere (c) et que s[i + 1] est 
//different du caractere (c)
//ligne 65 j = i + 1
//ligne 66 si s[i] est different de c et que s[i + 1] egale (c) ou s[i +1] =
//fin de chaine
//ligne 68 le double pointeur str[index] = fonction copie (string de depart, 
//[i] de depart, longueur)
//ligne 69, si le malloc n'a pas fonctionne, free malloc

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = ft_calloc(sizeof(char *), (count_words(s, c) + 1));
	if (!s || !split)
		return (0);
	split = pointerwriter(split, s, c);
	return (split);
}
//ligne 91 fonction finale
//ligne 93 creation du double poiteur de sortie  	[]
//													[]
//ligne 95 creation du nombre de malloc de sortie
//ligne 98 ecriture des doubles pointeurs
//ligne 99 retour 	
