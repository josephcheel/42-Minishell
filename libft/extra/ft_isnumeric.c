/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:11:27 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/03 03:08:30 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isnumeric(char *str)
{
	char *nbr;
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	nbr = ft_strtrim(str, " ");
	if (nbr[0] == '-' || nbr[0] == '+')
		nbr++;
	if (nbr == NULL || *nbr == '\0')
	{
		free(nbr);
		return (0);
	}
	while (nbr[i] != '\0')
	{
		if (!ft_isdigit(nbr[i]))
		{
			free(nbr);
			return (0);
		}
		i++;
	}
	free(nbr);
	return (1);
}
