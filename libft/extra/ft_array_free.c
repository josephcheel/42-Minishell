/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:10:40 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 13:16:00 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	**ft_array_free(char **Array, int i)
{
	while (i > 0)
		free(Array[--i]);
	free(Array);
	return (NULL);
}
