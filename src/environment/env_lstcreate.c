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

t_env	*ft_create_new_node(char *id, char *value)
{
	t_env	*result;

	result = malloc(sizeof(t_env));
	result->id = id;
	result->value = value;
	result->next = NULL;
	return (result);
}

t_env	*ft_insert_at_head(t_env **head, t_env *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return (node_to_insert);
}

t_env	*ft_insert_at_end(t_env **head, t_env *node_to_insert)
{
	t_env	*temp;

	if (!head)
		return (node_to_insert);
	temp = *head;
	if (!temp)
		*head = node_to_insert;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node_to_insert;
	}
	return (*head);
}

void	ft_insert_after_node(t_env *node_to_insert_after, t_env *newnode)
{
	newnode->next = node_to_insert_after->next;
	node_to_insert_after->next = newnode;
}
