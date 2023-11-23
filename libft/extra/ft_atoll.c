/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:59:15 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 13:14:31 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_is_bigger_maxll(char *str)
{
	int	negative;

	negative = 0;
	if (str[0] == '-')
		negative = 1;
	if (ft_strcmp(str, "-9223372036854775808") == 0)
		return (0);
	else if (ft_strcmp(str, "9223372036854775807") == 0)
		return (0);
	else if (ft_strcmp(str, "-9223372036854775808") > 0 && negative == 1)
		return (1);
	else if (ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	return (0);
}

long long int	ft_atoll(const char *str)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;
	if (ft_is_bigger_maxll((char *)str) == 1)
		return (0);
	while (*str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == ' ' )
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result * sign);
}
