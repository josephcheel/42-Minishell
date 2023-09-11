/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:48:35 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/07 18:23:02 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*tmp2;

	ret = 0;
	if (!lst)
		return (0);
	ret = NULL;
	while (lst)
	{
			tmp = f(lst->content);
			tmp2 = ft_lstnew(tmp);
		if (!tmp2)
		{
			del(tmp);
			ft_lstclear(&ret, del);
			return (0);
		}
		ft_lstadd_back(&ret, tmp2);
		lst = lst->next;
	}
	return (ret);
}
//ligne 17 et 18 et 19 creation de trois pointeurs
//ligne 27 au pointeur temp on donne un element qui contient la fonction
//ligne 28 au second pointeur temporaire on attribue la fonction de
//creation de maillon avec comme parametre le pointeur tmp
//ligne 29 si le pointeur ne contient rien,
//ligne 31 on efface le pointeur de fonction (f) 
//ligne 32 on efface l'adresse de (ret)
//ainsi qe la fonction (del)
//ligne 35 on ajoute un element (tmp2) a ret
//ligne 36 on incremente
