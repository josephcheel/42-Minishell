/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:22:44 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/03 17:44:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}
// ligne 19 si il s'agit d'un nombre negatif, 
// ligne 21 on ecrit le - en mode char dans fd
// ligne 22 nbr prend la valeur de n * -1 en (unsigned int)
// ligne 24 si non
// ligne 25 nbr prend la valeur de n en (unsigned int)
// ligne 26 si nbr est plus grand ou egal a 10
// ligne 27 recursivite, exemple avec 23, 23 / 10 = 2 donc retour au debut de
// la fonction avec 2 pour nbr
// ligne 28 on ecrit en mode char dans fd le modulo 10 auquel on ajoute 48 pour
// obtenir la valeur ASCII
