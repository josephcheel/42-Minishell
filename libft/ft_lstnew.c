/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:41:07 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/06 13:53:46 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
//ligne 15 fonction qui cree un nouveau maillon d'une liste avec 
//une valeur(content)
//ligne 17 ccreation d'un pnteur qui sera notre maillon
//ligne 19 assignation d'un malloc
//ligne 22 maillon qui pointe vers le maillon content contient la valeur content
//ligne 23 maillon qui pointe vers next contient la valeur NULL 
