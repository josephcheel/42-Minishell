/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:31:52 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/08 16:50:35 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;
	t_list *temp;
	
	counter = 0;
	temp = lst;
	while (temp)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}
