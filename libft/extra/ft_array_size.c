/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:10:43 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 13:15:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_array_size(char	**array)
{
	int		count;
	char	**ptr;

	count = 0;
	ptr = array;
	while (*ptr != NULL)
	{
		count++;
		ptr++;
	}
	return (count);
}
