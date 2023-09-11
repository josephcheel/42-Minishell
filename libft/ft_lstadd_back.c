/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:11:24 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/06 12:28:06 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
					last = ft_lstlast(*lst);
					last->next = new;
		}
		else
				*lst = new;
	}
}
//ligne 17 creation du pointeur last
//ligne 19 tant qu-on est dans lst
//ligne 23 on se deplace sur le dernier element de la liste
//ligne 24 on ajoute l-element new
//ligne 27 adresse du pointeur
