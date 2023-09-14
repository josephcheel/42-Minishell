/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:50:06 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/07 11:59:40 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					negative;
	int					result;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
			result = result * 10 + str[i] - '0';
			i++;
	}	
	return (result * negative);
}
/*
ligne 34:    tant qu'on a un digit
ligne 36:    result = (0 * 10) + val ascii premier digit - val ascii 0
exemple(45)  result = (0 * 10) +         52              -    48       result = 4
			 result = (4 * 10) +         53              -    48       result = 45
*/
