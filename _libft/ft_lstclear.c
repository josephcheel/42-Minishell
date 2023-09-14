/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:41:27 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/06 13:13:33 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
//ligne 17 creation d'un pointeur temporairei
//ligne 19 si il n'y a ni la fonction de suppression, ni
//l-element, ni le pointeur vers element
//ligne 20 fin
//ligne 21 tant quil y a un element et son pointeur
//lignne 23 le pointeur tmp devient l'adresse de pointeur de next
//ligne 24 fpnction de suppression d'un element
//le pointeur d-element prend l'adresse de l'element
