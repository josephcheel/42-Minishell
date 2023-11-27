/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:52 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/11/18 21:14:52 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environment.h"

t_env	*ft_envnew(char *id, char *value)
{
	t_env	*str;

	str = malloc(sizeof(t_env));
	if (!str)
		return (NULL);
	str->id = ft_strdup(id);
	str->value = ft_strdup(value);
	str->next = NULL;
	return (str);
}

void	ft_envadd_back(t_env **lst, t_env *new)
{
	t_env	*ret;

	if (*lst)
	{
		ret = ft_envlast(*lst);
		ret->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}

t_env	*ft_envlast(t_env *lst)
{
	t_env	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}