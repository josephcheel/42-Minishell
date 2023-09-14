/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:00:56 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/07 12:16:27 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
	i++;
	}	
	return (i);
}	
//ligne 15 fonction de comptage de decimales d'un entier avec gestion 
//de grands nombres(long)
//ligne 20 gestion des nombres negatifs dans cette fonction
//ligne 30 retourne le nombre de decimales

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	un;
	size_t			len;

	len = nbrlen(n);
	if (n < 0)
	un = (n * -1);
	else
	un = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		str[len] = '\0';
		len--;
		if (n < 0)
			str[0] = '-';
		else if (n == 0)
			str[0] = '0';
		while (un > 0)
		{	
			str[len--] = (char)(un % 10 + '0');
				un = un / 10;
		}	
	}	
	return (str);
}
//ligne 39 creation d-un pointeur sur char vu que ce sera le retour
//ligne 42 len sera utilisee pour connaitre la longueur en 
//remplacement de nbrlen
//ligne 44 gestion des nombres negatifs dans cette fonction
//ligne 48 creation du malloc de taille d'un char * longeur + 1
//ligne 49 si str a ete cree
//ligne 51 on ajoute '\0'  au bout de str
//ligne 52 len -1
//ligne 53 si n est plus petit 0, on ajoute '-' au debut
//ligne 55 ou si n egal 0 on ecrit '0'
//ligne 57 tant que n nonsigne est plus grand que 0
//ligne 59 copie dans str[len] en mode (char) modulo de 10 de (un) + ''
//ligne 60 et 61 on decale d-un decimale vers la gauche 
