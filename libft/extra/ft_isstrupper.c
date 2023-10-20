/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:18:06 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 13:18:21 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isstrupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isupper(str[i]))
			return (0);
		i++;
	}
	return (1);
}
