/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:49:26 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/06 12:21:21 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
	lst = lst ->next;
	}
	return (lst);
}
//ligne 17 tant qu'on est dan lst
//ligne 21 on se deplace d'un maillon vers next
//ligne 19 si le maillon qui pointe vers next est NULL, 
//on retourne le maillon
