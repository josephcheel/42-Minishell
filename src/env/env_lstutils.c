/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:52 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/04 20:54:01 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/environment.h"

t_env *ft_find_id(t_env *head, char *id)
{
	t_env *tmp;
	tmp = head;
	while(tmp != NULL)
	{
		if (ft_strcmp(tmp->id, id) == 0)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

t_env *ft_find_value(t_env *head, char *value)
{
	t_env *tmp;
	tmp = head;
	while(tmp != NULL)
	{
		if (ft_strcmp(tmp->value, value) == 0)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

int	ft_listsize(t_env *head)
{
	int		len;
	t_env	*temp;

	len = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

